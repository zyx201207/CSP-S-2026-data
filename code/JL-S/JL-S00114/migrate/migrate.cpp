#include <bits/stdc++.h>

using namespace std;
int n,n1;long long d,x[2000001];//fghubjrghhhhhhhghhhhhhghhghhghghhhhhhg
int ans,maxcs,maxn;
void lj(int cs,long long u,long long v){
    if(v-u<=d){
        if(maxcs>cs+1){
            maxcs=cs+1;
            maxn=1;
        }else if(maxcs==cs+1){
            maxn++;
        }
    return ;
    }
    for(long long i=d;i>=1;i--){
        lj(cs+1,u+i,v);
    }
}
int main()
{
//    freopen("migrate.txt","r",stdin);
    freopen("migrate.in","r",stdin);
    freopen("migrate.out","w",stdout);
    int C,N;
    cin>>C>>N;
    for(int I=1;I<=N;I++){
        n1=0;bool u=1;
        cin>>n>>d;
        for(int i=1;i<=n;i++){
            long long w;
            cin>>w;
            if((i==1 or w-x[i-1]<=d) && u){
                x[i]=w;
                n1++;
            }else{
                u=0;
                continue;
            }
        }
        for(int i=1;x[n1]-x[i]>d;i++){
            for(int j=n1;x[j]-x[i]>d;j--){
                maxcs=1e9;
                maxn=0;
                lj(0,i,j);
                if(maxn==2) ans++;
            }
        }
    cout<<ans<<endl;
    ans=0;
    }
    return 0;
}
