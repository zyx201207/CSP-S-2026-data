#include<bits/stdc++.h>
#define int long long
using namespace std;
const int maxn=5e5+5;
int a[maxn],n,m,pre[maxn];
signed main()
{
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);
    cin>>n>>m;
    int last=0,sum=0,ans=0,tot=0;
    for(int i=1;i<=n;i++)
    {
        cin>>a[i];
    }
    sort(a+1,a+n+1);
    for(int i=1;i<=n;i++)
    {
        pre[i]=pre[i-1]+a[i];
        int lt=0,rt=i+1;
        while(lt+1!=rt)
        {
            int mid=(lt+rt)>>1;
            if(a[i]*mid-(pre[i]-pre[i-mid])<=m)
            {
                lt=mid;
            }else
                rt=mid;
        }
       ans=max(ans,lt); 
    }
    cout<<ans;
}