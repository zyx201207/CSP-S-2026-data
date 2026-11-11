#include<bits/stdc++.h>
using namespace std;
int c,t;
int n,d,a[1000005];
bool k[1000005];
int dfs(int x,int y,int s,int steps){
    if(x==y&&steps==s){ return 1;}
    else{
        int cnt=0;
        for(int i=x+1;i<=y;i++){
            if(a[i]-a[x]<=d){
                cnt=cnt+dfs(i,y,s,steps+1);
                //cout<<i<<" "<<y<<" "<<steps+1<<'\n';
            }
        }
        return cnt;
    }
}
int main(){
    freopen("migrate.in","r",stdin);
    freopen("migrate.out","w",stdout);
    ios::sync_with_stdio(false);
    cin.tie(0);cout.tie(0);
    cin>>c>>t;
    while(t--){
        int ans=0;
        cin>>n>>d;
        for(int i=1;i<=n;i++){
            cin>>a[i];
        }
        for(int i=1;i<=n;i++){
            for(int j=i+2;j<=n;j++){
                memset(k,0,sizeof(k));
                int s=1+(a[j]-a[i])/d;
                if(dfs(i,j,s,0)==2){
                    ans++;
                }
                //cout<<dfs(i,j,s,0)<<"\n";
            }
        }
        cout<<ans<<'\n';
    }
    return 0;
}
