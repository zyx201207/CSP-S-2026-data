#include<bits/stdc++.h>
using  namespace std;
int c,t,ans,n,d,biao[5004],shenme=5;
struct lu1{
int shu,chang;
}lu;
void dfs(int qi,int zhong,int chan){
    for(int i=qi+1;i<=n;i++){
        if(biao[i]-biao[qi]>d) return;
        if(i==zhong){
            if(chan+1<lu.chang||lu.shu==0){
                lu.shu=1;
                lu.chang=chan+1;
                return;
            }else if(chan+1==lu.chang){
                lu.shu++;
                return;
            }else return;
        }
        dfs(i,zhong,chan+1);
    }
}
int main(){
   freopen("migrate.in","r",stdin);
   freopen("migrate.out","w",stdout);
   cin>>c>>t;
   while(t--){
    cin>>n>>d;
    ans=0;
    for(int i=1;i<=n;i++){
        cin>>biao[i];
    }
    for(int i=1;i<=n;i++){
        for(int j=i+1;j<=n;j++){
            if(biao[j]-biao[i]<=d) continue;

            lu.shu=0;
            lu.chang=2100000000;
            dfs(i,j,0);
            if(lu.shu==2) ans++;
        }
    }
    cout<<ans<<endl;
   }
}
