#include<iostream>
#include<cstdio>
using namespace std ;
#define T 12345

long long n , m ;
int a[T] ;
int main()
{
    freopen("crystal.in" , "r" , stdin) ;
    freopen("crystal.out" , "w" , stdout) ;
    cin >> n >> m ;
    for(int i = 0 ; i < n ; i++)
        cin >> a[i] ;

    if(n == 1)
        cout << 1 ;
    if(n == 2)
    {
        if(abs(a[1] - a[0]) > m)
        {
            cout << 1 ;
        }
    }


    fclose(stdin) ;
    fclose(stdout) ;
    return 0 ;
}
