#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define int long long
int T;
int a[500005];
int n,ans=0,mn=INT_MAX;
ll d;
int solve(int u,int v){
    int cnt=0;
    queue<pair<int,int>>q;
    q.push({u,0});
    while(!q.empty()){
            //if(u==1&&v==5) cout<<"test"<<endl;
            int x=q.front().first,y=q.front().second;
            q.pop();
            if(x==v){
                if(y==mn) cnt++;
                else if(y<mn){
                    cnt=1,mn=y;
                }
                continue;
            }
            if(y>=mn) continue;
            for(int i=x+1;i<=v;i++){
                if(a[i]-a[x]>d) break;
                q.push({i,y+1});
            }
    }
    return cnt==2?1:0;
}
signed main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    freopen("migrate.in","r",stdin);
    freopen("migrate.out","w",stdout);
    cin>>T>>T;
    while(T--){
        ans=0;
        cin>>n>>d;
        for(int i=1;i<=n;i++){
            cin>>a[i];
        }
        for(int u=1;u<n;u++){
            for(int v=u+1;v<=n;v++){
                mn=INT_MAX;
                //scout<<u<<' '<<v<<endl;
                ans+=solve(u,v);
            }
        }
        cout<<ans<<endl;
    }
    return 0;

}
