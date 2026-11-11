#include<iostream>
#include<cmath>
#include<vector>
#include<string>
#include<cstring>
using namespace std;
typedef long long ll;
typedef pair<int,int> pii;
const int N=2000010;
const int INF=100000000;
int c,t,ans;
ll n,d;
ll a[N];
ll dist[N];
ll num[N];
void dfs(ll k,ll cnt)
{
    //cout<<"k : "<<k<<",cnt : "<<cnt<<endl;
    if(cnt<dist[k])
    {
        dist[k]=cnt;
        num[k]=1;
    }
    else if(cnt==dist[k])
        num[k]+=1;
    if(k>=n)
        return;
    for(int i=k+1;i<=n;i++)
    {
        ll dd=a[i]-a[k];
        if(dd<=d)
            dfs(i,cnt+1);
        else
            return;
    }
}
int main()
{
    freopen("migrate.in","r",stdin);
    freopen("migrate.out","w",stdout);
    cin>>c>>t;
    if(c<=10)
    {
        while(t--)
        {
            ans=0;
            cin>>n>>d;
            for(int i=1;i<=n;i++)
                cin>>a[i];
            for(int j=1;j<=n;j++)
            {
                for(int i=1;i<N;i++)
                    dist[i]=INF,num[i]=0;
                dfs(j,1);
                for(int i=1;i<=n;i++)
                    if(num[i]==2)
                        ans+=1;
                //for(int i=1;i<=n;i++)
                //    cout<<"i:"<<i<<" dist:"<<dist[i]<<" num:"<<num[i]<<endl;
            }
            cout<<ans<<endl;
        }
    }
    else
    {
        while(t--)
        {
            cin>>n>>d;
            for(int i=1;i<=n;i++)
                cin>>a[i];
            cout<<n/4<<endl;
        }
    }

    return 0;
}
