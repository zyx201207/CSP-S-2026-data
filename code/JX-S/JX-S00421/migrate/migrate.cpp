#include<bits/stdc++.h>
using namespace std;
int n,d,x[2000005],length,cnt,ans;
void dfs(int a,int b,int step){
    if(a==b){
        if(length>step){
            cnt=1;
            length=step;
        }
        else if(length==step){
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
        for(int u=1;u<n;u++){
            for(int v=u+1;v<=n;v++){
                length=1000000000;
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
