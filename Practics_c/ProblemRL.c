#include <stdio.h>
#include <stdlib.h>
#include <assert.h>

int iabs(int x) { return (x < 0) ? -x : x;}

int eu_mod(int x, int y) {
    assert(y != 0);
    int r = x % y;
    if(r < 0)
        r += iabs(y);
    return r;
}

int gcd(int x, int y)
{
    assert(y != 0);
    int q;

    while(1) {
        q = eu_mod(x, y);
        x = y;
        if (q == 0)
            break;
        y = q;
    }
    return y;
}



int main()
{
    int a, b, sc;
    sc = scanf("%d%d", &a, &b);
    if(sc == 2 && b != 0) {
        printf("%d\n", gcd(a,b));
        printf("a / b == %d\na %% b == %d", a / b, a % b);
    }
    else printf("Wrong result!"); 
}