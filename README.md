#Description
An quicksort killer implemention based on [A Killer Adversary for Quicksort](http://www.cs.dartmouth.edu/~doug/mdmspe.pdf).

As we know, the quicksort average time complexity O(nlogn): 
```
   if every paritition divide the array two equal half, the recursive tree height 
   is O(logn), each layer of the tree cost O(n). So total complexity is O(nlogn).
```   
The killer will make a bad array to make every paritition select nealy lowest pivot, 
so the partition will can not divide the array equality, instead, it will be very
unblanced(n elements will probably be divide into 1:n-1).

Each partition's cost is O(n), there are nealy n times partition 
(because of the bad array).So the total cost:
```
   O(n)*n = O(n^n)
```
More detals. In the implemention, each paritition will at most fill 2 elements.
The compare operations :
```
   n-1 + (n-3) + .. + 1 = n - (n-1+1)n/4 = n*n/4 (Nealy equal) 
```
