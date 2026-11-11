#include<bits/stdc++.h>
#define int long long
#define N 2000005
#define mod 998244353ll
using namespace std;
int O,t,n,d;
int a[N],b[N],sum[N];
int L[N],R[N];
int cnt;
int dl[N],dr[N];
vector<int> st[N],ed[N];
int cap[N];
#define M 305
int dis[M][M],way[M][M];
signed main(){
freopen("migrate.in","r",stdin);
freopen("migrate.out","w",stdout);
ios::sync_with_stdio(0);
cin.tie(0);cout.tie(0);
cin>>O>>t;
while(t--){
    cin>>n>>d;
    for(int i=1;i<=n;i++) cin>>a[i],b[i]=a[i]-a[i-1];
    if(n<=300){
        memset(dis,0x3f,sizeof(dis));
        memset(way,0,sizeof(way));
        for(int i=1;i<=n;i++){
            for(int j=i+1;j<=n;j++){
                if(a[j]-a[i]<=d){
                    dis[i][j]=1;
                    way[i][j]=1;
                }
            }
        }
        for(int k=1;k<=n;k++){
            for(int i=1;i<k;i++){
                for(int j=k+1;j<=n;j++){
                    if(dis[i][j]>dis[i][k]+dis[k][j]){
                        dis[i][j]=dis[i][k]+dis[k][j];
                        way[i][j]=way[i][k]*way[k][j]%mod;
                    }
                    else if(dis[i][j]==dis[i][k]+dis[k][j]){
                        (way[i][j]+=way[i][k]*way[k][j]%mod)%=mod;
                    }
                }
            }
        }
        int ans=0;
        for(int i=1;i<=n;i++){
            for(int j=i+1;j<=n;j++){
                if(way[i][j]==2){
                    ans++;
                }
            }
        }
        cout<<ans<<'\n';
        continue;
    }
    b[1]=0;
    for(int i=1;i<=n;i++) sum[i]=sum[i-1]+b[i],dl[i]=dr[i]=0,st[i].clear(),ed[i].clear(),cap[i]=0;
    dl[n+1]=dr[n+1]=0;st[n+1].clear(),ed[n+1].clear(),cap[n+1]=0;
    cnt=1;
    L[1]=1,R[1]=2;
    int l=1;
    // cout<<"sum"<<endl;
    // for(int i=1;i<=n;i++) cout<<b[i]<<' ';
    // cout<<endl;
    // for(int i=1;i<=n;i++) cout<<sum[i]<<' ';
    // cout<<endl;
    for(int r=2;r<=n;r++){
        if(sum[r]-sum[l]<=d){
            R[cnt]=r;
        }
        else{
            cnt++;
            while(sum[r]-sum[l]>d){
                l++;
            }
            if(l==r){
                cnt--;
                continue;
            }
            L[cnt]=l;
            R[cnt]=r;
        }
    }
    for(int i=1;i<=cnt;i++) st[L[i]].push_back(i);
    for(int i=1;i<=cnt;i++) ed[R[i]].push_back(i),cap[L[i]]++,cap[R[i]+1]--;
    // cout<<"cnt "<<cnt<<endl;
    // for(int i=1;i<=cnt;i++) cout<<L[i]<<' '<<R[i]<<endl;
    // cout<<"--------"<<endl;
    // for(int i=1;i<=n;i++){
    //     if(st[i].size()>1 or ed[i].size()>1) cerr<<"TANG!"<<endl;
    // }
    for(int i=1;i<=n;i++){
        cap[i]+=cap[i-1];
    }
    deque<int> q;
    for(int i=1;i<=n;i++){
        if(ed[i].size()){
            q.pop_front();
        }
        if(st[i].size()){
            q.push_back(st[i][0]);
        }
        if(!cap[i]){
            dl[i]=0;
            continue;
        }
        if(cap[i]==1){
            if(ed[i-1].size()) dl[i]=1;
            else{
                dl[i]=dl[i-1]+1;
            }
            continue;
        }
        if(cap[i]>cap[i-1]){
            dl[i]=dl[i-1]+1;
            continue;
        }
        if(cap[i]==cap[i-1]){
            if(!st[i].size()){
                dl[i]=dl[i-1]+1;
                continue;
            }
            else{
                dl[i]=dl[i-1]+1;
                continue;
            }
        }
        if(cap[i]<cap[i-1]){
            dl[i]=i-L[q.front()]+1;
            continue;
        }
    }
    q.clear();
    for(int i=n;i>=1;i--){
        if(st[i].size()){
            q.pop_front();
        }
        if(ed[i].size()){
            q.push_back(ed[i][0]);
        }
        if(!cap[i]){
            dr[i]=0;
            continue;
        }
        if(cap[i]==1){
            if(st[i+1].size()) dr[i]=1;
            else{
                dr[i]=dr[i+1]+1;
            }
            continue;
        }
        if(cap[i]>cap[i+1]){
            dr[i]=dr[i+1]+1;
            continue;
        }
        if(cap[i]==cap[i+1]){
            if(!ed[i].size()){
                dr[i]=dr[i+1]+1;
                continue;
            }
            else{
                dr[i]=dr[i+1]+1;
                continue;
            }
        }
        if(cap[i]<cap[i+1]){
            dr[i]=R[q.front()]-i+1;
            continue;
        }
    }
    int ans=0;
    for(int i=1;i<=cnt;i++){
        if(L[i]+1==R[i]) continue;
        int p=L[i];
        if(ed[p+1].size() and cap[p]==2){
            ans+=dl[p-1]*dr[p+2];
        }
    }
    cout<<ans<<'\n';
}
return 0;
}

/*
Oct31==Dec25?
thus 2026=null as sale /kx
*/

/*
#include<bits/stdc++.h>
#define int long long
#define N 500005
using namespace std;
int n,a[N],m,sum[N];
int qst(int l,int r){
    int o=a[r]*(r-l+1);
    int p=sum[r]-sum[l-1];
    // if(l==1 and r==3){
    //     cout<<o<<' '<<p<<' '<<m<<endl;
    // }
    if(o-p<=m) return 1;
    return 0;
}
signed main(){
    ios::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    cin>>n>>m;
    for(int i=1;i<=n;i++) cin>>a[i],sum[i]=sum[i-1]+a[i];
    sort(a+1,a+n+1);
    int ans=0;
    int l=1;
    for(int r=1;r<=n;r++){
        while(l<=r and !qst(l,r)) l++;
        // cout<<l<<' '<<r<<endl;
        ans=max(ans,r-l+1);
    }
    cout<<ans;
    return 0;
}

#include<bits/stdc++.h>
#define int long long
#define N 505
#define M 500005
#define fi first
#define se second
using namespace std;
int n,m,d,q,O,w[M];
vector<pair<int,int>> lne[M];
int dis[N][N];
signed main(){
    // freopen("subway.in","r",stdin);
    // freopen("subway.out","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    cin>>O>>n>>m>>d>>q;
    for(int i=1;i<=m;i++) cin>>w[i];
    for(int i=1;i<=n;i++){
        int k;
        cin>>k;
        for(int j=1;j<=k;j++){
            int p,d;
            cin>>p>>d;
            lne[p].push_back({i,d});
        }
    }
    memset(dis,0x3f,sizeof(dis));
    int maxx=dis[0][0];
    for(int i=1;i<=m;i++){
        for(auto nx:lne[i]){
            for(auto ny:lne[i]){
                if(nx==ny) continue;
                int d=nx.se+ny.se;
                int o=min(dis[nx.fi][ny.fi],dis[ny.fi][nx.fi]);
                dis[nx.fi][ny.fi]=dis[ny.fi][nx.fi]=min(o,d);
            }
        }
    }
    // for(int i=1;i<=n;i++){
    //     for(int j=1;j<=n;j++){
    //         cout<<"way "<<i<<' '<<j<<": "<<dis[i][j]<<endl;
    //     }
    // }
    for(int i=1;i<=n;i++) dis[i][i]=0;
    for(int k=1;k<=n;k++){
        for(int i=1;i<=n;i++) for(int j=1;j<=n;j++) dis[i][j]=min(dis[i][j],dis[i][k]+dis[k][j]);
    }
    // for(int i=1;i<=n;i++){
    //     for(int j=1;j<=n;j++){
    //         cout<<"way "<<i<<' '<<j<<": "<<dis[i][j]<<endl;
    //     }
    // }
    while(q--){
        int x,y,ans=0;
        cin>>x>>y;
        ans=maxx;
        for(auto nx:lne[x]){
            for(auto ny:lne[y]){
                if(dis[nx.fi][ny.fi]==maxx) continue;
                ans=min(ans,dis[nx.fi][ny.fi]+nx.se+ny.se);
            }
        }
        cout<<ans+w[x]+w[y]<<'\n';
    }
    return 0;
}

*/