#include<bits/stdc++.h>
using namespace std;
struct num
{
    int x;
    int c2;
};

inline int count1(int x)
{
    int cnt=0;
    while(x>0)
    {
        if(x%2==1)  cnt++;
        x/=2;
    }
     if(x%2==1)  cnt++;
    return cnt;
}
bool cmp(num x,num y)
{
    return x.c2<y.c2;
}
int main()
{
    freopen("and.in","r",stdin);
    freopen("and.out","w",stdout);
    num a[1000000];
    int n;
    cin>>n;
    int dp[10000];
    for(int i=0;i<n;i++)
    {
        cin>>a[i].x;
    }
    sort(a,a+n,cmp);
    int x=a[0].x;
    dp[0]=x;

    for(int i=0;i<n;i++)
    {
        for(int j=i;j<n;j++)
        {
            dp[i]=max(dp[i]&a[j].x,dp[i]);
        }
    }
    cout<<dp[n-1];
    return 0;
}
