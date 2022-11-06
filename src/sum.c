#include "sum.h"
#include <assert.h>

int sum(int a[], int n)
{
    assert(n >= 0); /* Precondition */

    if (n > 0) /* If the lenght of the array is larger than 0, this statement runs */
    {
        return a[n-1] + sum(a, n - 1); /* Calculating sum with recursion */
    }
    else /* Base case: the sum of the array when n = 0 is 0 */
    {
        return 0;
    }
}