#include <iostream>
using namespace std; 

const int N = 100000;

int n;
int gas, solid_num;
int val[N]; //bad array
int ptr[N]; //index of bad array
int candidate;
int cmp_times;

// x, y is the ptr value, indicate the index of val array
int cmp(const int x, const int y) {
  cmp_times++;
  if (val[x] == gas && val[y] == gas) {
    if (candidate == x)
      val[x] = solid_num++; //fill element from small to big
    else
      val[y] = solid_num++;
  }
  if (val[x] == gas)
    candidate = x;
  if (val[y] == gas)
    candidate = y;
  return val[x] - val[y];
}

int partition(int l, int r, int* array) {
  // select mid number as pivot value
  swap(array[l], array[(l+r) >> 1]);
  int pivot = array[l];
  int j = l;
  for (int i = l+1; i <= r; i++)
    if (cmp(array[i], pivot) < 0)
      swap(array[++j], array[i]);
  swap(array[j], array[l]);
  return j;
}

void quick_sort(int l, int r, int* array) {
  if (l < r) {
    int pos = partition(l, r, array);
    quick_sort(l, pos-1, array);
    quick_sort(pos+1, r, array);
  }
}

// Generate the bad array, make the quick_sort time complexity O(n*n)
void anti_quick_sort(int n) {
  gas = n-1;
  cmp_times = 0;
  candidate = solid_num = 0;

  // in order to not modify the bad array val
  // using ptr as the index fo val
  for (int i = 0; i < n; ++i) {
    ptr[i] = i; // index of val array
    val[i] = gas; 
  }

  quick_sort(0, n-1, ptr);
}

int main() { 
  while (cin >> n) {
    anti_quick_sort(n);
    cout << (1+n)*n/2 << " " << cmp_times << endl;
  }

  return 0;
}
