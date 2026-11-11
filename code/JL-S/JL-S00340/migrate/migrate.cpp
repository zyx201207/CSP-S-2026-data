#include<bits/stdc++.h>
using namespace std;
#define int long long
const int N=2145140;
int c,t,n,d,a[N],f[N],sum[N],num,ans,pre[N];
signed main()
{
    freopen("migrate.in","r",stdin);
    freopen("migrate.out","w",stdout);
    ios::sync_with_stdio(0);cin.tie(0);
    cin>>c>>t;
    while(t--)
    {
        cin>>n>>d;ans=0;
        for(int i=1;i<=n;i++)
        {
            cin>>a[i];
        }
        if(c==11||c==12)
        {
            f[1]=0;
            sum[1]=1;
            num=0;
            for(int i=2,l=1,r=1;i<=n;i++)
            {
                while(a[i]-a[l]>d&&l<i)l++,num-=sum[l-1];
                while(f[r]<=f[l]&&r<i)r++,num+=sum[r-1];
                f[i]=f[l]+1;
                if(l==i)break;
                sum[i]=num;
                if(num==2)ans+=n-i+1;
            }
            cout<<ans<<'\n';
            continue;
        }
        if(c==13||c==14)
        {
            int mid=0;
            for(int i=1;i<=n;i++)
            {
                if(a[n]-a[i]<=d)
                {
                    mid=i;
                    break;
                }
            }
            for(int i=n,l=n;i>=1;i--)
            {
                while(a[i]-a[l]<=d&&l>=1)l--;
                l++;
                pre[i]=l;
            }
            for(int i=1,r=1;i<mid;i++)
            {
                while(a[r]-a[i]<=d&&r<=n)r++;
                r--;
                int L=r+1,R=n+1;
                while(L+1<R)
                {
                    int mid=(L+R)/2;
                    if(r-pre[mid]+1>=2)L=mid;
                    else R=mid;
                }
                if(r-pre[L]+1==2)ans+=n-L+1;
            }
            cout<<ans<<'\n';
            continue;
        }
        for(int st=1;st<=n;st++)
        {
            f[st]=0;
            sum[st]=1;
            num=0;
            for(int i=st+1,l=st,r=st;i<=n;i++)
            {
                while(a[i]-a[l]>d&&l<i)l++,num-=sum[l-1];
                while(f[r]<=f[l]&&r<i)r++,num+=sum[r-1];
                f[i]=f[l]+1;
                if(l==i)break;
                sum[i]=num;
                if(num==2)ans++;
            }
        }
        cout<<ans<<'\n';
    }
    return 0;
}
