
#include<bits/stdc++.h>
#define int long long 
using namespace std;
const int N=1e6+10;
int n,d;
int x[N];
int ans=0;
unordered_map<int,int>m;
int minn=1e18;
struct node{
    int s,cnt;
};
void bfs(int a,int b){
    if(abs(x[a]-x[b])<=d)return ;
    queue<node>q;
    minn=1e18;
    q.push({a,0});  
    while(q.size()){
        node t=q.front();
        q.pop();
        if(abs(x[t.s]-x[b])<=d){
            minn=min(minn,t.cnt);
            m[t.cnt]++;
            continue;
        }
        if(minn<t.cnt)continue;
        for(int i=t.s+1;i<=b;i++){
            if(abs(x[t.s]-x[i])<=d){
                q.push({i,t.cnt+1});
            }
        }
    }
}
signed main(){
    freopen("migrate.in","r",stdin);
    freopen("migrate.out","w",stdout);
    ios::sync_with_stdio(false);
    cin.tie(0),cout.tie(0);
    int c,T;
    cin>>c>>T;
    while(T--){
        ans=0;
        cin>>n>>d;
        for(int i=1;i<=n;i++){
            cin>>x[i];
        }
        if(c<=6){
            m.clear();
            for(int i=1;i<=n;i++){
                for(int j=i+1;j<=n;j++){
                    if(abs(x[j]-x[j-1])>d)break;
                    bfs(i,j);
                    if(m[minn]==2){
                        // cout<<"aa"<<i<<" "<<j<<'\n';
                        ans++;
                    }
                    m.clear();
                }
            }
            cout<<ans<<'\n';
            continue;
        }
        else if(c==13||c==14){
            int o=(x[1]+x[n])/2;
            int p=lower_bound(x+1,x+1+n,o)-x;
            if(x[n]-x[1]<=d){
                cout<<0<<'\n';
                continue;
            }
            int p1=upper_bound(x+1,x+1+n,x[1]+d)-x-1;
            int p2=lower_bound(x+1,x+1+n,x[n]-d)-x;
            if(p1==p+1&&p2==p){
                for(int i=1;i<=p;i++){
                    if(abs(x[i]-x[p+2])>d)ans++;
                }
            }
            else if(p1==p&&p2==p-1){
                for(int i=n;i>=p;i--){
                    if(abs(x[i]-x[p-2])>d)ans++;
                }
            }
            cout<<ans<<'\n';
        }
    }   
    return 0;
}