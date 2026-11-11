#include<cstdio>
#include<algorithm>
constexpr int N=2e6+5;
int c,t,n,target;
long long d,x[N],cnt;
unsigned int Min,ways;
inline void dfs(int pos,int cost){
    if(pos==target){
        if(cost<Min){Min=cost;cnt=1;}
        else if(cost==Min)++cnt;
        return;
    }for(int i=pos+1;i<=target;++i){
        if(x[i]-x[pos]<=d)dfs(i,cost+1);
        else break;
    }
}int main(){
    freopen("migrate.in","r",stdin);
    freopen("migrate.out","w",stdout);
    setvbuf(stdin,NULL,_IOFBF,1<<22);
    setvbuf(stdout,NULL,_IOFBF,1<<18);
    scanf("%d%d",&c,&t);
    do{
        scanf("%d%lld",&n,&d);
        for(int i=1;i<=n;++i)scanf("%lld",&x[i]);
        int tot=0;
        for(int i=1;i<n;++i){
            for(int j=i+1;j<=n;++j){
                target=j;Min=-1;cnt=1;
                dfs(i,0);
                if(cnt==2)++tot;
            }
        }printf("%d\n",tot);
    }while(--t);
    return 0;
}
