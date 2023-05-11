/*
Segment Tree
What is a Segment Tree?
Why do we need a Segment Tree?
How to Build a Segment Tree?
How to query and update a range of elements?
Set of leet code questions based on the Segment Tree.

What is a Segment Tree?
A segment tree is a data structure used for efficiently quarrying from a range of an array and updating an element or intervals of an array. 
This data structure keeps a record of all the segments of the original array from coarser to finer elements. In other words, actually, it is an array data structure that represents the conceptual tree which is divided into the nodes, and every node represents a segment or an interval of the original array.
It allows performing range queries, such as finding the sum, minimum, maximum, or any other associative operation, over a specified range of indices in the array.
In any query which targets a specific range, the response can be given quickly from the respective node representing the range.
Why do we need a Segment Tree?
We need ST as a data structure to store precomputed values of all the ranges of an array so that for any query based on a range can be served in a minimal time delay. Take for example an array of 1 M elements and n number of queries per second of finding sum from the index location "i" to "j". If we follow the brute force approach of finding the sum for every query, the read latency will be worse. Instead of this traditional approach, if we have a data structure that has a pre-computed sum for all the ranges of the array. The read latency will definitely improve to a great extent. In order to update the value at any index will only update the segments related to the index in the query. So, at the expense of slight write latency, we can improve the read latency to a great extent.
So, In the naive solution, if the array size is N and the number of queries is M, the time complexity will be O(MN). As a result, this approach will not scale very for the million queries on an array of sizes in gigabytes. On the other hand, if we go with a segment tree DS, the time complexity will be O(MlogN) which is far better and scalable. 
How to Build a Segment Tree?
A segment tree is a binary tree that has a leaf as an individual element of the tree. All the node represent a segment and the root node represent the original array.
The main idea of the segment tree is to divide the array into smaller segments or intervals until each segment represents a single element. Each node in the segment tree represents a segment of the array, and the tree is typically represented as an array or a tree-like structure.
To segregate the large array into the smaller array or into tree nodes (in terms of tree), we need to see how many nodes including leaves are needed. The maximum number of nodes required is the length of an array we need.
let's say we have an array of length 4. For example, [1,2,3,4].
After creating segments, it would look like as below.
                                 1 2 3 4
                                    /\
                                1,2   3,4
                                 /\    /\
                                1  2  3  4
So, the number of nodes needed depends on the length of the original array.
If the original array length is even, # of nodes are (2*n -1)
If the original array length is odd, find the next number (n) which is a power of 2, and the # of nodes will be (2*n - 1).
Example: 
if (n == 4) ST array length would be (2*4–1) = 7
if (n == 5) ST array length would be (2*8–1) = 15
So the time complexity to build this array is O(N), and the space complexity to accommodate all the nodes is O(N).
In order to build a segment tree, we need to remember a few points. 
How to find the left and right child of a node and the parent node of any non-root 
a node in a tree?

left = 2 * root_index + 1
right = 2 * root_index + 2
Prent = node/2-1;

How to query and update a range of elements?
Let's take an example: 
An array of length 6, {-1,3,4,0,2,1}
We need to find the minimum in different ranges. 
                   {-1,3,4,0,2,1} 

                /(0 to 2)          \ (ans: minimum is 0 from 3to 5)
        {-1, 3, 4}                {0,2,1}  
   (0 - 1)/ \                 (3-4) /\ (5-5)
      {-1,3} {4}               {0,2} {1}
        /\                       /\ 
    -1     3                   0    2
To solve any query, we need to check 3 conditions for the range limit. 
No overlap (There the query range does not fall into the lower and upper bound) For example, the query is to find the minimum from index 2 to 3 and we are at a node that covers the range from 0 to 1. That means, there is no overlap and the return from this node should be irrelevant. In this case, it should be INT_MAX. 
Partial overlap (one-half of the query is on the left child and another one is on the right child). For example, the query is to find the minimum from index 2 to 3 and we are at a node that covers the range from 0 to 5 and the mid is 2. So we need to trace the left and right nodes.
Total overlap ( query range matches with the segment node's range). For example, the query is to find a minimum from 2 to 3 and we are the node that has a range from 2 to 3. That means, there is total overlap and we can return from this node.
*/

Class SegmentTree{
  public:
    int n;
    vector<int> tree;
    SegmentTree(int size)
    {
      n = size;
      int k = 0;
      k = (n & 1) ? (int)ceil(log2(n << 1)) : n;
      k = (k*2) - 1;
      tree.resize(k, INT_MAX);
    }

    void ConstructSegTree(vector<int> arr, int low, int high, int pos, vector<int> &tree){
      if (low == high)
      {
        tree[pos] = input[low];
        return;
      }
      int m = low + (high - low)/2;
      ConstructSegTree(arr,low, m, pos*2+1, tree);
      ConstructSegTree(arr,m+1, high, pos*2+2, tree);
      tree[pos] = min(tree[pos*2+1], tree(pos*2+2));
    }
};
  
  
  
  
  
  
