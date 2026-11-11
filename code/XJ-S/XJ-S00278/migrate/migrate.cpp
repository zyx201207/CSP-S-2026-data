#include<iostream>
#include<algorithm>
#include<vector>
#include<cstring>
#include<queue>
const int N=2e6+10;
long long n,d,ans,c;
long long x[N];
void DFS(int now,int v,long long cnt,long long ww){
    if(now==v){
        if(cnt==ww) c++;
        return ;
    }
    for(int i=now+1;i<=v;i++){
        if(x[i]-x[now]<=d)
            DFS(i,v,cnt+1,ww);
        else break;
    }
    return ;
}
long long DFS1(int now,int v,long long cnt){
    if(now==v)
        return cnt;
    for(int i=v;i>now;i--){
        if(x[i]-x[now]<=d){
            return DFS1(i,v,cnt+1);
        }
    }
    return 1e18;
}
void calc(int u,int v){
    c=0;
    long long cnt=DFS1(u,v,0);
    DFS(u,v,0,cnt);
    if(c==2) ans++;
    return ;
}
int main(){
    freopen("migrate.in","r",stdin);
    freopen("migrate.out","w",stdout);
    int c,t;
    std::cin>>c>>t;
    while(t--){
        std::cin>>n>>d;
        for(int i=1;i<=n;i++)
            std::cin>>x[i];
        for(int i=1;i<n;i++){
            for(int j=i+1;j<=n;j++){
                calc(i,j);
            }
        }
        std::cout<<ans<<"\n";
        ans=0;
    }
    return 0;
}