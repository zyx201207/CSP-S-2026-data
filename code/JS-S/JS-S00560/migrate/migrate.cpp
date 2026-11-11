#include<iostream>
#define int long long
using namespace std;
bool mst;
const int N=2e6+6;
int ans,n,d,x[N],f[N],rp[N],gs[N];
void work1()
{
    cin>>n>>d,ans=0;
    for(int i=1;i<=n;i++)cin>>x[i];
    for(int st=1;st<=n;st++)
    {
        for(int i=1;i<=n;i++)
            f[i]=rp[i]=gs[i]=0;
        f[st]=0,rp[0]=st,gs[st]=1;
        for(int j=st,i=st+1;i<=n;i++)
        {
            while(x[i]-x[j]>d)j++;
            if(j==i)break;
            rp[f[i]=f[j]+1]=i;
            gs[i]=gs[i-1]+gs[rp[f[j]]]-gs[j-1];
        }
        for(int i=st+1;i<=n;i++)
        {
            int nw=gs[i]-gs[i-1];
            if(nw==2)ans++;
        }
    }
    cout<<ans<<'\n';
}
void work2()
{
    cin>>n>>d,ans=0;
    for(int i=1;i<=n;i++)cin>>x[i];
    if(n==1){cout<<"0\n";return;}
    int del=d/(x[2]-x[1]);
    if(del<=1){cout<<"0\n";return;}
    cout<<max(n-2*del+1,0ll)<<'\n';
}
bool med;
signed main()
{
    ios::sync_with_stdio(false);
    cin.tie(0),cout.tie(0);
    freopen("migrate.in","r",stdin);
    freopen("migrate.out","w",stdout);
    int c,t;cin>>c>>t;
    while(t--)
    {
        if(c<=10)work1();
        else if(c<=12)work2();
    }
    cerr<<(1.0*clock())/CLOCKS_PER_SEC<<endl;
    cerr<<abs(&mst-&med)/1024.0/1024.0<<"MB\n";
}