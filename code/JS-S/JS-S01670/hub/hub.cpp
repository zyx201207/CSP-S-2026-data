#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N=2e6+10;
int deep[N],n;
int head[N<<1],to[N],nxt[N],cnt,k;
void add(int x,int y){
    nxt[cnt]=head[x];
    to[++cnt]=y;
    head[x]=cnt;
    return ;
}
int read(){
    int f=1,x=0;
    char ch='\n';
    while(ch<'0'||ch>'9'){
        ch=getchar();
        if(ch=='-') f=-1;
    }
    while('0'<=ch&&ch<='9'){
        x=x*10+(ch-'0');
        ch=getchar();
    }
    return f*x;
}
void write(int x){
    if(x<10){
        putchar(x+'0');
        return ;
    }
    write(x/10);
    x%=10;
    putchar(x+'0');
}
int point;
int in[N];
int ans;
int dfs(int dep,int fa,int z,int used){
    //cout<<dep<<' '<<z<<' '<<used<<endl;
    bool l=0;
    //cout<<used<<endl;
    if(used==(-1)*z){
        ans++;
        l=1;
        used=z;
    }
    int cnt=0;
    int re=(-1)*z;
    //cout<<used<<' '<<used-1<<endl;
    //cout<<re<<endl;
    for(int i=head[dep];i;i=nxt[i]){
            //cnt++;
        int u=to[i];
        if(u==fa) continue;
        cnt++;
        if(l) used=max(used,dfs(u,dep,z,z-1));
        else if(l) used=max(used,dfs(u,dep,z,max(re-2,used-1)));
    }
    if(cnt==0) return used;
    return used;
}
bool check(int x){
    ans=0;
    dfs(point,0,x,0);
    //cout<<x<<' '<<ans<<endl;
    if(ans<=k) return true;
    else return false;
}
void solve(){
    cin>>n>>k;
    memset(in,0,sizeof in);
    memset(deep,0,sizeof deep);
    memset(head,0,sizeof head);
    cnt=0;
    for(int i=1;i<n;i++){
        int x,y;
        cin>>x>>y;
        add(x,y);
        add(y,x);
        in[x]++,in[y]++;
    }
    for(int i=1;i<=n;i++){
        if(in[i]==1){
            point=i;
            break;
        }
    }
    int l=1,r=n;
    while(l<r){
        int mid=(l+r+1)>>1;
        if(check(mid)){
            r=mid-1;
        }else l=mid;
    }
    cout<<l<<'\n';
}
signed main(){
    freopen("hub.in","r",stdin);
    freopen("hub.out","w",stdout);
    int _;
    cin>>_>>_;
    while(_--){
        solve();
//        cout<<"1\n";
    }
    return 0;
}
