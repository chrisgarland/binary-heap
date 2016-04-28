/*
 * =============================================================================
 *
 *       Filename:  min-heap.c
 *
 *    Description:  Implementation of a min binary heap
 *
 *        Version:  1.0
 *        Created:  28/04/2016 20:25:06
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  CHRIS GARLAND (15560955), c.garland@student.curtin.edu.au
 *   Organization:  
 *
 * =============================================================================
 */
#include "heap.h"

#include <stdlib.h>


#define PARENT_INDEX(i)       (((i)-1) / 2)
#define LEFT_CHILD_INDEX(i)   (((i)*2) + 1)
#define RIGHT_CHILD_INDEX(i)  (((i)*2) + 2)



/* 
 * ===  FUNCTION  ==============================================================
 *         Name:  swap_elements
 *  Description:  Takes a heap plus two index integers, swaps  the elements
 * =============================================================================
 */
static void swap_elements (Heap* heap, int i, int j)
{
        int buffer;

        buffer = heap->array[i];
        heap->array[i] = heap->array[j];
        heap->array[j] = buffer;
}	/* -----  end of function swap_elements  ----- */


/* 
 * ===  FUNCTION  ==============================================================
 *         Name:  min_heapify
 *  Description:  Ensures min-heap properties are maintained. Takes (as input) 
 *                an array A (the heap) and 'i' an index of the array. A[i] 
 *                will float down until it is no longer larger than either of 
 *                it's children. Uses recursive approach
 * =============================================================================
 */
void min_heapify (Heap* heap, int i)
{
        int smallest, buffer, len = heap->length;
        int lchild_i = LEFT_CHILD_INDEX(i);
        int rchild_i = RIGHT_CHILD_INDEX(i);

        if (lchild_i < len && heap->array[lchild_i] < heap->array[i]) 
                smallest = lchild_i;
        else
                smallest = i;

        if (rchild_i <= len && heap->array[rchild_i] < heap->array[smallest])
                smallest = rchild_i;
                
        if (i != smallest) {
                swap_elements(heap, i, smallest);
                min_heapify(heap, smallest);
        }
}	/* -----  end of function min_heapify  ----- */

