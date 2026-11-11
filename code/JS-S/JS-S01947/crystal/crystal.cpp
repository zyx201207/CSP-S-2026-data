#include<bits/stdc++.h>
using namespace std;
const int N=5e5+5;
long long n,m,a[N],pre[N],ans;
int main()
{
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);
    cin>>n>>m;
    for(int i=1;i<=n;i++) cin>>a[i];
    sort(a+1,a+1+n);
    for(int i=1;i<=n;i++) pre[i]=pre[i-1]+a[i];
    for(int i=1;i<=n;i++)
    {
        int lt=1,rt=i;
        long long res=1;
        while(lt<=rt)
        {
            int mid=(lt+rt)/2;
            if((mid*a[i]-(pre[i]-pre[i-mid]))<=m)
            {
                res=mid;
                lt=mid+1;
            }
            else rt=mid-1;
        }
        ans=max(ans,res);
    }
    cout<<ans;
    return 0;
}
