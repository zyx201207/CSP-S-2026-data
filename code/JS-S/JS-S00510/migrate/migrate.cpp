#include<bits/stdc++.h>
#define int long long
using namespace std;
int c,t,n,d,ans=INT_MAX,k;
int x[2000010];
void dfs(int u,int v,int dis,int cnt){
    if(u==v){
        if(cnt<ans){
            k=1;
            ans=cnt;
        }
        else if(cnt==ans){
            k++;
        }
        return;
    }
    for(int i=u+1;i<=v;i++){
        dis+=abs(x[i]-x[i-1]);
        if(dis<=d){
            dfs(i,v,0,cnt+1);
        }
        else{
            break;
        }
    }
}
signed main(){
    freopen("migrate.in","r",stdin);
    freopen("migrate.out","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin>>c>>t;
    while(t--){
        cin>>n>>d;
        for(int i=1;i<=n;i++){
            cin>>x[i];
        }
        int cnt=0;
        for(int u=1;u<=n;u++){
            for(int v=u+1;v<=n;v++){
                ans=INT_MAX;
                k=0;
                dfs(u,v,0,0);
                if(k==2){
                    cnt++;
                }
            }
        }
        cout<<cnt<<endl;
    }
    return 0;
}
