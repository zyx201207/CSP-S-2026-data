#include<bits/stdc++.h>
using namespace std;
int n,d,x[50000005],l,cnt,ans;
void dfs(int a,int b,int step){
    if(a==b){
        if(l>step){
            cnt=1;
            l=step;
        }
        else if(l==step){
            cnt++;
        }
       return;
    }
    for(int i=a+1;i<=n;i++){
        if(x[i]-x[a]<=d){
            step++;
            dfs(i,b,step);
            step--;
        }
        else break;
    }
}
int main(){
    freopen("migrate.in","r",stdin);
    freopen("migrate.out","w",stdout);
    int c,t;
    cin>>c>>t;
    while(t--){
        cin>>n>>d;
        ans=0;
        for(int i=1;i<=n;i++){
            cin>>x[i];
        }
        for(int u=1;u<=n;u++){
            for(int v=u;v<=n;v++){
                l=10000000;
                cnt=0;
                dfs(u,v,0);
                if(cnt==2){
                    ans++;
                }
            }
        }
        cout<<ans<<endl;
    }
    return 0;
}
