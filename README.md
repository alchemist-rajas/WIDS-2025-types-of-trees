# WIDS-2025-types-of-trees
All resources related to this WIDS will be uploaded here. For each week, we will provide resources for theory and pseudocdoes for standard algorithms. We will also recommned some problems for you to try for mostly all weeks so you can feel confident about using these data structures. The following is a rough week by week plan for this project, subject to change. 
### Week 1 : Implementing and using general trees. 
### Week 2 : Binary search trees, Heaps and B-trees 
#### Problems  :  (added the  solutions for these in a separate folder)
#### 1.LC 94
#### 2.LC 101
#### 3.LC 108
#### 4.LC 110
#### 5.LC 144
#### 6.LC 145
#### 7.LC 501
#### 8.LC 530
#### 9.LC 700
#### 10.LC 783
#### 11.LC 98
#### 12.LC 102 (medium,hint: does this look like some traversal you already know?)
#### 13.LC 235 (pretty tough to get the right and efficient idea. Try out examples on paper to get some hints)
#### 14.LC 1569 (A bonus and a very hard problem, that we expect anybody to do based on week1 + week2 knowledge)
### Week 3 : RB trees and AVL trees
In Week 3, the focus was on advanced self balancing binary search trees, specifically **Red-Black Trees (RBT)**. Unlike standard BSTs, which can become skewed and degrade to O(n) time complexity, Red-Black Trees ensure the tree remains balanced, guaranteeing **O(log n)** time complexity for insertion, deletion, and lookup operations.

### Key Concepts Covered
* **Red-Black Properties:**
    1.  Every node is either red or black.
    2.  The root is always black.
    3.  No two red nodes can be adjacent (a red node cannot have a red parent).
    4.  Every path from a node to its descendant NULL nodes has the same number of black nodes.
* **Rotations:** Understanding Left and Right Rotations as mechanisms to restructure the tree without violating BST properties.
* **Fixup Logic:** Implementing a post-insertion repair process to correct violations of Red-Black properties (re-coloring and rotating).

### Implementation Details
The project involved implementing the core insertion logic for a Red-Black Tree in C++.

* **`insert`**: Standard BST insertion followed by a call to `fixup`.
* **`leftrotate` & `rightrotate`**: Pointer manipulation to pivot nodes around a specific axis, essential for balancing.
* **`fixup`**: The algorithm that checks the color of the parent and "uncle" nodes to decide whether to re-color or rotate the tree to maintain balance.

### Performance
* **Search**: O(log n)
* **Insert**: O(log n)
* **Delete**: O(log n)

### Week 4 : Tries and suffix tries 
### Week 5 : Fenwick Trees and Segment trees (Some basic applications only) 
### Week 6 : Treaps (We doubt we will able to cover this due to the time constraint we have, but we will try our best).
