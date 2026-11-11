#include<bits/stdc++.h>
using  namespace std;
//struct zhantai{
  //  int huan1;
//};
//struct xianlu{
//    zhantai
//};
int n,m,kouting[500],xian[500],vis[500],tu[503][503],ans,c,d,q,k,huan[500][500],zhan,a,b;
void dfs(int qi,int zhong,int xian,int t){
    if(t>ans) return;
    for(int i=1;i<=m;i++){
        if(tu[qi][i]!=0&&vis[i]==0){
            int jia=0;
            if(qi==a) jia+=huan[tu[qi][i]][qi];
            else if(tu[qi][i]!=xian) jia+=huan[xian][qi]+huan[tu[qi][i]][qi];
            if(i==zhong){
                ans=min(ans,t+jia+huan[tu[qi][i]][i]);
                return;
            }
            vis[qi]=1;
            dfs(i,zhong,tu[qi][i],t+jia);
            vis[qi]=0;

        }
    }

}
int main(){
    freopen("subway.in","r",stdin);
    freopen("subway.out","w",stdout);
cin>>c>>n>>m>>d>>q;
for(int i=1;i<=m;i++){
    cin>>kouting[i];
}
for(int i=1;i<=n;i++){
    cin>>k;
    for(int j=1;j<=k;j++){
        cin>>zhan;
        cin>>huan[i][zhan];
        xian[j]=zhan;
    }
    for(int j=1;j<=k;j++){
        for(int p=j+1;j<=k;j++){
            tu[xian[j]][xian[p]]=i;
            tu[xian[p]][xian[j]]=i;
        }
    }
}
for(int i=1;i<=q;i++){
    cin>>a>>b;
    ans=2100000000;
    vis[a]=1;
    dfs(a,b,0,0);
    vis[a]=0;
    cout<<ans+kouting[a]+kouting[b]<<endl;
}
}
