#include<bits/stdc++.h>
using namespace std;
#define int long long
#define llg long long
#define sig signed
#define usg unsigned
#define ull unsigned long long
int c,t,n,d,a[2000005];
int pre[2000005],nxt[2000005];
unordered_map<int,int>mp;
vector<int>g[2000005];
void add(int x,int sum,int cnt){
    if(cnt>0){
        ++mp[cnt*n*n+sum];
    }
    for(int i=0;i<g[x].size();++i)add(g[x][i],sum+x,cnt+1);
}
void ese(int x,int sum,int cnt){
    if(cnt>0){
        --mp[cnt*n*n+sum];
    }
    for(int i=0;i<g[x].size();++i)add(g[x][i],sum+x,cnt+1);
}
signed main(){
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    freopen("migrate.in","r",stdin);
    freopen("migrate.out","w",stdout);
    cin>>c>>t;
    while(t--){
        cin>>n>>d;
        for(int i=1;i<=n;++i)cin>>a[i];
        pre[1]=1;
        for(int i=2;i<=n;++i){
            pre[i]=pre[i-1];
            while(a[pre[i]]+d<a[i])++pre[i];
        }
        nxt[n]=n;
        for(int i=n-1;i>=1;--i){
            nxt[i]=nxt[i+1];
            while(a[nxt[i]]-d>a[i])--nxt[i];
        }
        if(11<=c&&c<=12){
            int ans=0,tmp=nxt[1]-1;
            if(tmp==0)ans=0;
            else if(tmp==1)ans=0;
            else{
                ans=max(0ll,n-tmp*2+1);
            }
            cout<<ans<<"\n";
            continue;
        }
        for(int i=1;i<=n;++i)g[i].clear();
        for(int i=1;i<=n;++i){
            if(nxt[i]!=i)g[nxt[i]].push_back(i);
        }
        mp.clear();
        int last=1,ans=0;
        for(int i=1;i<=n;++i){
            int cnt=0,now=pre[i],sum=0;
            while(pre[now]!=now){
                sum+=now;
                ++cnt;
                ans+=mp[cnt*n*n+sum+1];
                now=pre[now];
            }
            //cout<<"ask "<<i<<"\n";
            add(i,0,0);
            //cout<<"add "<<i<<"\n";
            while(last<=n&&nxt[last]<=i){
                ese(last,0,0);
                //cout<<"ese "<<last<<"\n";
                ++last;
            }
        }
        cout<<ans<<"\n";
    }
    return 0;
}
