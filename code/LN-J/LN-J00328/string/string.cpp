#include<iostream>
#include<cstring>
using namespace std;
char s[2000000];
int a[2000000];
int main()
{
    freopen("string1.in" , "r" , stdin);
    freopen("string1.ans" , "w" , stdout);
    int n , x = 0 , cnt = 0;
    cin >> n;
    for(int i = 0; i < n ; i++)
    {
        cin >> a[i] >> s[i];
        x += a[i];
    }
    int l= 0 , r = x-1;
    for(int i = 0 , j = n-1 ; l <= x/2 ; l++ , r--)
    {
        int b = 0;
        for(int z = 0 ; z <= i ; z++)
            b += a[z];
        if(l > b-1)
            i++;
        int c = 0;
        for(int z = n-1 ; z >= j ; z--)
            c += a[z];
        if(x-r+1 <= c-1)
            j--;
        if(s[i] != s[j-1])
            cnt++;
    }
    cout << cnt;
    return 0;
}
