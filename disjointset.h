#ifndef DISJOINTSET_H
#define DISJOINTSET_H

/**
 * DisJoint Set data structure:
 * makeSet(x) creates a singleton set {x}
 * find(x) returns ID of the set containing x:
 *  * if x and y lie in the same set, then find(x) == find(y)
 *  * otherwise find(x) != find(y)
 * Union(x,y) merges two sets containing x and y
 *
 * In order to divide the maze region into disjoint sets.
 *  preProcess(Maze)
 *  {
 *      for each cell c in maze:
 *          makeSet(c)
 *      for each cell in maze:
 *          for each neighbor n of c:
 *              union(c,n)
 *  }
 *
 *  isReachable(A,B)
 *  {
 *      return find(A)==find(B)
 *  }
 *
 *
 * The Efficient structure:
 * Each set is a upgoing tree and the ID of each set
 * is the root of the tree.
 * To join each (Union) the sets, just hang the shallower
 * tree to the root of the deeper tree.
 * Through each find method, we can attach all the nodes
 * directly to the root. (Path Compresion)
 * The final tree is going to be very shallow
 *
 * The exctra needed arrays
 * parent[] which partent [i] = the parent of node i
 * if parent [i]=i then i is the root
 * rank[] is the height of each subtree (node)
 * rank of root is zero
 */

#endif // DISJOINTSET_H
