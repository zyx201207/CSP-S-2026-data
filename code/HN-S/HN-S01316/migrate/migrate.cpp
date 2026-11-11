#include<bits/stdc++.h>
#define int long long
#define ls(x) (x<<1)
#define rs(x) (x<<1|1)
using namespace std;
const int N=2e6+10;
const int INF=1e18;
int n,d,dp[N],pre[N],a[N],dis[N],ans,ord[N],SS[N];
int t[N<<2];
vector<int>dd[N],ss[N];
bool cmp(int A,int B){return dis[A]==dis[B]?A<B:dis[A]<dis[B];}
void pushup(int x){
    t[x]=min(t[ls(x)],t[rs(x)]);
}
void build(int x,int L=1,int R=n){
    t[x]=INF;
    if(L==R)return;
    int mid=(L+R)>>1;
    build(ls(x),L,mid);
    build(rs(x),mid+1,R);
}
void upd(int x,int pos,int val,int L=1,int R=n){
    if(pos<0 || pos>n)return;
    if(L==R){t[x]=val;return;}
    int mid=(L+R)>>1;
    if(pos<=mid)upd(ls(x),pos,val,L,mid);
    else upd(rs(x),pos,val,mid+1,R);
    pushup(x);
}
int qry(int x,int l,int r,int L=1,int R=n){
    if(l<0 || r<0 || l>n || r>n || l>r)return INF;
    if(l<=L&&R<=r)return t[x];
    int mid=(L+R)>>1,res=INF;
    if(l<=mid)res=min(res,qry(ls(x),l,r,L,mid));
    if(mid<r)res=min(res,qry(rs(x),l,r,mid+1,R));
    return res;
}
void solve(){
    cin>>n>>d;ans=0;
    for(int i=1;i<=n;++i)cin>>a[i],dp[i]=0,pre[i]=-1;
    for(int i=1;i<=n;++i){
        int pos=lower_bound(a+1,a+1+n,a[i]-d)-a;
        if(pos>=1 && pos<=n && a[pos]+d>=a[i])pre[i]=pos;
    }
    for(int l=1;l<=n;++l){
        for(int i=1;i<=n;++i)dis[i]=INF;
        build(1);
        dis[l]=0;
        upd(1,l,0);
        for(int j=l+1;j<=n;++j){
            //for(int k=pre[j];k<=j;++k)dis[j]=min(dis[j],dis[k]+1);
            dis[j]=qry(1,pre[j],j)+1;
            if(dis[j]<=n)upd(1,j,dis[j]);
        }
        for(int i=1;i<=n;++i)dp[i]=0;
        for(int i=0;i<=n;++i)dd[i].clear(),ss[i].clear(),SS[i]=0;
        for(int i=l;i<=n;++i)if(dis[i]<=n)dd[dis[i]].push_back(i);
        for(int i=1;i<=n-l+1;++i)ord[i]=i+l-1;
        sort(ord+1,ord+1+n-l+1,cmp);
        dp[l]=1;
        ss[0].push_back(1);
        for(int i=1;i<=n-l+1;++i){
            int cur=ord[i];
            int ddd=dis[ord[i]];
            if(ddd>n)continue;
            if(pre[cur]==cur)continue;
            if(ddd-1<0)continue;
            if(!dd[ddd-1].size())continue;
            int pos=lower_bound(dd[ddd-1].begin(),dd[ddd-1].end(),pre[cur])-dd[ddd-1].begin();
            if(!(pos>=0 && pos<(int)(dd[ddd-1].size()) && dd[ddd-1][pos]>=pre[cur] && dd[ddd-1][pos]<=cur))continue;
            int siz=(int)(ss[ddd-1].size())-1;
            dp[cur]=ss[ddd-1][siz];
            if(pos>0)dp[cur]-=ss[ddd-1][pos-1];
            SS[ddd]+=dp[cur];
            ss[ddd].push_back(SS[ddd]);
        }
        for(int i=l;i<=n;++i)if(dp[i]==2)++ans;
    }
    cout<<ans<<'\n';
}
signed main(){
    freopen("migrate.in","r",stdin);
    freopen("migrate.out","w",stdout);
    ios::sync_with_stdio(false);cin.tie(0),cout.tie(0);
    int c,T;cin>>c>>T;
    while(T--)solve();
    return 0;
}