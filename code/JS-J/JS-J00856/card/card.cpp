#include<bits/stdc++.h>
using namespace std;
int a[500006];
int g[500006];
int ans[200006];
int n,m;
void solve1(){
    for(int i=1;i<=n;i++){  
        int tot=0;
        for(int j=i;j<=n;j++){
            int mi=0;
            for(int k=1;k<=tot;k++) if(g[k]==a[j]){mi=k;break;}
            if(!mi) g[++tot]=a[j];
            else{
                for(int k=mi+1;k<=tot;k++) g[k]=0;
                tot=mi;
            }
        }
        for(int j=1;j<=tot;j++){
            ans[g[j]]++;
        }
    }
    for(int i=1;i<=m;i++) cout<<ans[i]<<" ";
}
void solveA(){
    for(int i=1;i<=n;i++){
        if(a[i+1]!=a[i]) ans[a[i]]=i;
    }
    for(int i=1;i<=m;i++) cout<<ans[i]<<" ";
}
int main(){
    freopen("card.in","r",stdin);
    freopen("card.out","w",stdout);
    cin>>n>>m;
    for(int i=1;i<=n;i++){
        cin>>a[i];
    }
    if(m<=500&&m<=200){
        solve1();
        return 0;
    }//baoli(1-6) 24points
    int f=1;
    for(int i=1;i<n;i++){
        if(a[i]>a[i+1]){
            f=0;break;
        }
    }
    if(f){
        solveA();
        return 0;
    }//A (7-9,20) 16points
    else{
        solve1();
        return 0;
    }//0
}