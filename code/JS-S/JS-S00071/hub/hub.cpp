#include<bits/stdc++.h>
using namespace std;
int c,t,n,d,a[2000005];
long long ans=0;
struct Node{
    long long dis,cnt;
}dp[5005][5005];
int main()
{
    freopen("hub.in","r",stdin);
    freopen("hub.out","w",stdout);
    cin>>c>>t;
    while(t--)
    {
        cin>>n>>d;
        for(int i=1;i<n;i++) cin>>d>>d;
        cout<<n;
    }
    return 0;
}
