#include<bits/stdc++.h>
using namespace std;
const int N=5e5+10;
long long int n,m,ans=1,ans1;
long long int a[N],b[N];
int main()
{
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);

    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin>>n>>m;
    for(int i=1;i<=n;i++)
    {
        cin>>a[i];
    }
    sort(a+1,a+1+n);
    for(int i=1;i<=n;i++)
    {
        b[i]+=b[i-1]+a[i];
    }
    for(int i=1;i<=n;i++)
    {
        ans1=0;
        for(int j=i;j<=n;j++)
        {
            long long int k=a[j]*(j-i+1);
            if(m>=(k-b[j]+b[i-1]))
            {
                ans1+=1;
            }
        }
        ans=max(ans,ans1);
    }
    cout<<ans;
    return 0;
}
