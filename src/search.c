#include "search.h"
#include <stdbool.h>
#include <assert.h>

bool search(int a[], int n, int x)
{
    assert(n >= 0); /* Precondition */

    /* Base case: If the lenght of the array is larger than 0,æ 
    and the value of the array at lenght n -1 id equal to x, this statement runs  */
    if (n > 0 && a[n - 1] == x)     
    {
        return true;
    }
    else if (n > 0 && a[n - 1] != x) /* Owtherwise, if the value isn't equal to x, run the function with n -1 (recursion) */
    {
        search(a, n - 1, x);
    }
    else /* Base case: If the value is not the array, it returns false */
    {
        return false;
    }
}