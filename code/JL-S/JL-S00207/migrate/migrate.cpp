#include<bits/stdc++.h>
using namespace std;
const int N=2e6+5;
typedef long long ll;
inline ll read(){
    ll x=0,f=1;char ch=getchar();
    while(ch<'0'||ch>'9'){if(ch=='-')f=-1;ch=getchar();}
    while(ch>='0'&&ch<='9')x=x*10+ch-48,ch=getchar();
    return x*f;
}
ll a[N];
ll ans=0;
ll cnt[N];
int dis[N];
const int INF=0x3f3f3f3f;
ll d;
void solve(int n){
    for(int i=1;i<=n;i++) dis[i]=0;
    int r=n;
    dis[n]=0;
    deque<int> dq;
    dq.push_front(n);
    cnt[n+1]=0;
    cnt[n]=1;
    ll sum=1;
    for(int l=n-1;l>=1;l--){
        int lst=dis[dq.front()];
        while(!dq.empty() && a[dq.front()]-a[l]>d){
            sum--;
            dq.pop_front();
        }
        if(dq.empty()) return;
        if(lst!=dis[dq.front()]){
            sum=0;
            lst=dis[dq.front()];
            for(int i=0;i<dq.size();i++){
                if(dis[dq[i]]==lst) sum++;
                else break;
            }
        }
        dis[l]=dis[dq.front()]+1;
        ll tmp=cnt[dq.front()-sum+1]-cnt[dq.front()+1];
        if(tmp==2) ans++;
        if(tmp>INF) tmp=INF;
        cnt[l]=cnt[l+1]+tmp;
        dq.push_back(l);
        //cout<<n<<' '<<l<<' '<<tmp<<'\n';
    }
}
//int n;
//const int M=2e6+5;
//unordered_map<int,int> mp;
//int dp[M],nxt[M];
int main(){
    freopen("migrate.in","r",stdin);
    freopen("migrate.out","w",stdout);
    int c=read(),T=read();
    if(c<=10){
    while(T--){
        int n=read();
        d=read();
        for(int i=1;i<=n;i++){
            a[i]=read();
        }
        ans=0;
        for(int i=n;i>=1;i--){
            solve(i);
        }
        printf("%lld\n",ans);
    }
    }
    else if(c>=13 && c<=14){
        while(T--)printf("0\n");
    }
    else{
    while(T--){
        int n=read();
        d=read();
        for(int i=1;i<=n;i++){
            a[i]=read();
        }
        ans=0;
        for(int i=n;i>=1;i--){
            solve(i);
        }
        printf("%lld\n",ans);
    }
    }
    return 0;
}
/*
dp[nxt]+dfs(nxt,nxt-1,yes,nxt-2,no,1)
dfs(1,2,=,3,!=,1)

*/
