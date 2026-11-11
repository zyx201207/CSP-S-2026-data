#include<bits/stdc++.h>
using namespace std;

#ifdef LOCAL
#define debug(x) cerr<<#x<<':'<<x<<'\n'
#define debug_arr(arr,i) cerr<<#arr<<'['<<i<<":]"<<(arr)[i]<<'\n'
#define debug_string(s) cerr<<#s<<':'<<s<<'\n'
#else
#define debug(x)
#define debug_arr(arr,i)
#define debug_string(s)
#endif

const int MAXN=2e6+5;
const int INF=0x3f3f3f3f;
int c,t,n,d,minlen=INF,ans;
int x[MAXN];
priority_queue<int>pq;

long long read(){
    long long x=0,f=1;
    char c=getchar();
    while(c<'0'||c>'9'){
        if(c=='-') f=-1;
        c=getchar();
    }
    while(c>='0'&&c<='9'){
        x=(x<<3)+(x<<1)+(c^48);
        c=getchar();
    }
    return x*f;
}
void write(long long x){
    if(x<0){
        x=-x;
        putchar('-');
    }
    if(x>9) write(x/10);
    putchar(x%10+'0');
    return;
}
void init(){
    ans=0;
    return;
}
void dfs(int id,int cnt,int end){
    if(id==end){
        minlen=min(minlen,cnt);
        pq.push(cnt);
        while(pq.top()>=minlen) pq.pop();
        return;
    }
    if(cnt>minlen) return;
    for(int i=id+1;x[i]-x[id]<=d&&i<=end;i++) dfs(i,cnt+1,end);
    return;
}
int main(){
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    freopen("migrate.in","r",stdin);
    freopen("migrate.out","w",stdout);
    cin>>c>>t;
    while(t--){
        cin>>n>>d;
        init();
        for(int i=1;i<=n;i++) cin>>x[i];
        for(int i=1;i<=n;i++){
            for(int j=1;j<=n;j++){
                minlen=INF;
                dfs(i,0,j);
                if(pq.size()==2) ans++;
                while(!pq.empty()) pq.pop();
            }
        }
        cout<<ans<<'\n';
    }
    return 0;
}