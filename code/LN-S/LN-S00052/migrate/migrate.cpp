#include<bits/stdc++.h>
using namespace std;
const int N=2e6+10;
long long ans[N];
long long a[N],n,C,T;
long long f[N],m;
int l,r;
long long ingans,ansn=0;
long long ingk=0; 

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    freopen("migrate.in","r",stdin);
    freopen("migrate.out","w",stdout);
    cin>>C>>T;
    while(T--)
    {
        cin>>n>>m;
        long long minn=INT_MAX;
        for(int i=1;i<=n;i++)
            cin>>a[i],f[i]=1e7+10,ans[i]=0,minn=min(minn,a[i]);
        for(int i=1;i<=n;i++)
            a[i]-=minn+1;
        ansn=0;
        ingans=0;
        for(int st=1;st<n;st++)
        {
            for(int i=1;i<=n;i++)
                ans[i]=0;
            l=r=st;
            ingans=0;
            f[st]=0;
            ans[st]=1;
            ingk=f[l];
            ingans=1;
            for(int i=st+1;i<=n;i++)
            {
                if(a[i]-a[i-1]>m)
                    break;
                while(f[r+1]==f[l]&&r+1<i)
                    r++,ingans+=ans[r];
                while(l<=r&&a[i]-a[l]>m)
                    l++,ingans-=ans[l-1];
                while(l>r&&r+1<i)
                {
                    r++;
                    ingans+=ans[r];
                    while(f[r+1]==f[l]&&r+1<i)
                        r++,ingans+=ans[r];
                    while(l<=r&&a[i]-a[l]>m)
                        l++,ingans-=ans[l-1];
                }
                f[i]=f[l]+1;
                ans[i]=ingans;
                if(ans[i]==2)
                    ansn++;

            }
        }
        cout<<ansn<<"\n";
    }
    return 0;
}