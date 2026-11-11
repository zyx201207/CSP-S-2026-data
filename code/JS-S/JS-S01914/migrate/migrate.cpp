#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
int const N=2e6+5;
ll n,d;
ll x[N],min_cnt=0,min_road=LONG_LONG_MAX;
void dfs(int t,int id,ll cost){

    if(id==t){
        //cout<<"**"<<t<<" "<<id<<" "<<cost<<endl;
        if(cost<min_road){
            //cout<<"&&\n";
            min_road=cost;
            min_cnt=1;
        }
        else if(cost=min_road){
           // cout<<"$$\n";
            min_cnt++;
        }
        return;
    }
    //cout<<t<<" "<<id<<" "<<cost<<endl;
    for(int i=id+1;i<=t;i++){
        auto tttt=lower_bound(x+1+id,x+1+t,x[id]+d);
        int k=*tttt;
        if(x[i]-x[id]<=d){
            dfs(t,i,cost+1);
        }
        else{
            break;
        }
       /*if(k-id<1){
            break;
        }
        else if(k-id<2){
             dfs(t,k,cost+1);
        }
        else{
            dfs(t,k,cost+1);
            dfs(t,k-1,cost+1);
        }*/
    }
}
void dfs2(int t,int id,ll cost){

    if(id==t){
        //cout<<"**"<<t<<" "<<id<<" "<<cost<<endl;
        if(cost<min_road){
            //cout<<"&&\n";
            min_road=cost;
            min_cnt=1;
        }
        else if(cost=min_road){
           // cout<<"$$\n";
            min_cnt++;
        }
        return;
    }
    //cout<<t<<" "<<id<<" "<<cost<<endl;
    for(int i=id+1;i<=t;i++){
        auto tttt=lower_bound(x+1+id,x+1+t,x[id]+d);
        int k=*tttt;
        /*if(x[i]-x[id]<=d){
            dfs(t,i,cost+1);
        }
        else{
            break;
        }*/
       if(k-id<1){
            break;
        }
        else if(k-id<2){
             dfs(t,k,cost+1);
        }
        else{
            dfs(t,k,cost+1);
            dfs(t,k-1,cost+1);
        }
    }
}
int main(){
    freopen("migrate.in","r",stdin);
    freopen("migrate.out","w",stdout);
    int c,T;
    scanf("%d%d",&c,&T);
    if(c>10){
         while(T--){
        scanf("%lld%lld",&n,&d);
        for(int i=1;i<=n;i++){
            scanf("%lld",&x[i]);
        }
        int ans=0;
        for(int i=1;i<n;i++){
            for(int j=i+1;j<=n;j++){
                min_cnt=0,min_road=LONG_LONG_MAX;
                dfs2(j,i,0);
                ans+=(min_cnt==2);
            }
        }
        printf("%d\n",ans);
        //cout<<endl;
    }
    return 0;
    }
    while(T--){
        scanf("%lld%lld",&n,&d);
        for(int i=1;i<=n;i++){
            scanf("%lld",&x[i]);
        }
        int ans=0;
        for(int i=1;i<n;i++){
            for(int j=i+1;j<=n;j++){
                min_cnt=0,min_road=LONG_LONG_MAX;
                dfs(j,i,0);
                ans+=(min_cnt==2);
            }
        }
        printf("%d\n",ans);
        //cout<<endl;
    }
    return 0;
}
/*

*/
