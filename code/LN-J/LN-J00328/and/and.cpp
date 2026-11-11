#include<iostream>
using  namespace std;
int a[100005] , dp[100005];
int m , n , max_ = -1;
int x ,y;
void ccc( x,  y)
{
    if(y > n)
        return ;
    for(int i = x ; i <= n-m+y; i++)
        max_ = max(max_ , a[x] & a[dp(i , y+1)]);
}
int main()
{
    freopen("and2.in" , "r" , stdin);
    freopen("and2.ans" , "w" , stdout);
    cin >> n >> m;
    for(int i = 0 ; i < n; i++)
    {
        cin >> a[i];
    }
    ccc(0,0);
    cout << max_;
}
