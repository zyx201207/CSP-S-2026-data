#include<bits/stdc++.h>
#define int long long
using namespace std;
typedef long long ll;
typedef pair<int,int> PII;
const int N=2e6+10,M=5e3+10;
int n,d;
ll a[N];
int ans[M];
int cnt[M];
int st[M];
void bfs(int s,int t){
    queue<int>q;
    q.push(s);
    ans[s]=1;
    while(q.size()){
        int x=q.front();
        for(int i=1;i<=n;i++){
            if(i==x) continue;
            if(abs(a[i]-a[x])<=d){
                if(ans[i]==ans[x]+1) cnt[i]+=x;
                if(!st[i]){
                    q.push(i);
                    st[i]=1;
                }
            }
        }
    }
}
void sol(){
    cin>>n>>d;
    for(int i=1;i<=n;i++) cin>>a[i];

    int anss=0;
    for(int i=1;i<=n;i++){
        for(int j=i+1;j<=n;j++){
            bfs(i,j);
            if(cnt[j]==2) anss++;
            memset(ans,0,sizeof(ans));
            memset(st,0,sizeof(st));
            memset(cnt,0,sizeof(cnt));
        }
    }
    cout<<anss<<"\n";
}
signed main(){
    freopen("migrate.in","r",stdin);
    freopen("migrate.out","w",stdout);
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int c,t;cin>>c>>t;
    while(t--){
        sol();
    }
    return 0;
}
