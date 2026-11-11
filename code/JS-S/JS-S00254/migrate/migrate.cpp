#include<bits/stdc++.h>
using namespace std;
long long c,t,x[200001],n,d,cnt,cnt1,ans=0;
void dfs(int step,int u,int v,int bn){
if(u==v&&bn==cnt1){
    cnt++;
    return;
}
for(int i=step+1;x[i]<=v&&i<=n;i++){
if(abs(x[i]-x[step])<=d)dfs(i,x[i],v,bn+1);
    else break;
}
}
int main(){
freopen("migrate.in","r",stdin);
freopen("migrate.out","r",stdout);
cin>>c>>t;
while(t--){
    cin>>n>>d;
ans=0;
    for(int i=1;i<=n;i++)cin>>x[i];
    for(int i=1;i<n;i++){
        for(int j=i+1;j<=n;j++){
                for(cnt1=1;cnt1<=j-i;cnt1++){
                cnt=0;
            dfs(i,x[i],x[j],0);
            if(cnt==2){
                ans++;
                break;
            }
            else if(cnt==0);
            else break;
        }
    }
    }cout<<ans<<"\n";
}

return 0;
}
