#include<bits/stdc++.h>
using namespace std;
int c,t,n,d;
int x[2000010];
int memo[5010][5010];
int temp[2000010];
int dfs01(int u,int v,int tmp){
    if(x[u+1]-x[u]>d)return 0x3f;
    if(memo[u][v]){
        temp[tmp+memo[u][v]]++;
        return memo[u][v];
    }
    if(x[v]-x[u]<=d){
        memo[u][v]=1+tmp;
        return memo[u][v];
    }
    for(int i=u;i<=v;i++){
        if(x[i]-x[u]>d){
            break;
        }
        if(!memo[u][v]){
            memo[u][v]=dfs01(i,v,tmp+1);
        }else{
            memo[u][v]=min(memo[u][v],dfs01(i,v,tmp+1));
        }
    }
    return memo[u][v];
}
void plan_M(){
    while(t--){
        cin>>n>>d;
        for(int i=1;i<=n;i++){
            cin>>x[i];
        }
        int ans=0;
        for(int i=1;i<=n-1;i++){
            for(int j=i+1;j<=n;j++){
                dfs01(i,j,0);
                for(int i=1;i<=n;i++){
                    if(temp[i]){
                        if(temp[i]==2){
                            ans++;
                        }
                        break;
                    }
                }
            }
        }
        cout<<ans;
    }
}
void plan_A(){
    while(t--){
        cin>>n>>d;
        for(int i=1;i<=n;i++){
            cin>>x[i];
        }
    }
}
void plan_B(){
    while(t--){
        cin>>n>>d;
        for(int i=1;i<=n;i++){
            cin>>x[i];
        }
    }
}
void plan_C(){
    while(t--){
        cin>>n>>d;
        for(int i=1;i<=n;i++){
            cin>>x[i];
        }
    }
}
int main(){
    freopen("migrate.in","r",stdin);
    freopen("migrate.out","w",stdout);
    cin>>c>>t;
    if(c<=10||c>=19){
        plan_M();
        return 0;
    }
    if(c=11&&c<=12){
        plan_A();
        return 0;
    }if(c==13||c==14){
        plan_B();
        return 0;
    }if(c>=15&&c<=18){
        plan_C();
    }
    fclose(stdin);
    fclose(stdout);
    return 0;
}