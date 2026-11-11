#include<bits/stdc++.h>
using namespace std;
#define int long long
const int maxn=2*1e6+5;
int c,T,n,d,a[maxn],mi=1e9,cnt=0;
void dfs(int st,int ed,int pos,int len){
    //if(st==1&&ed==4) cout<<st<<" "<<ed<<" "<<pos<<" "<<len<<"\n";
    if(pos==ed){
        mi=min(mi,len);
        return;
    }
    for(int i=pos+1;a[i]-a[pos]<=d&&i<=ed;++i){
        //if(st==1&&ed==4) cout<<pos<<" "<<i<<"\n";
        dfs(st,ed,i,len+1);
    }
}
void bfs(int st,int ed,int pos,int len){
    if(pos==ed){
        if(len==mi) cnt++;
        return;
    }
    for(int i=pos+1;a[i]-a[pos]<=d&&i<=ed;++i) bfs(st,ed,i,len+1);
}
signed main(){
    freopen("migrate.in","r",stdin);
    freopen("migrate.out","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0),cout.tie(0);
    cin>>c>>T;
    while(T--){
        int ans=0;
        cin>>n>>d;
        for(int i=1;i<=n;i++) cin>>a[i];
        for(int i=1;i<=n;i++){
            for(int j=i+1;j<=n;j++){
                mi=1e9,cnt=0;
                dfs(i,j,i,0);
                bfs(i,j,i,0);
                if(cnt==2) ans++;
            }
        }
        cout<<ans<<"\n";
    }
    return 0;
}
