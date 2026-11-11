#include <bits/stdc++.h>
using namespace std;
int c,t,n,d;
long long a[10005];
long long minn=0x3f3f3f3f,cut=0,ans=0;
inline void dfs(int x,int y,long long z){
    if(x==y){
        if(z<minn){
            minn=z;
            cut=1;
        }
        else if(z==minn){
            cut++;
        }
        return;
    }
    if(z>=minn)return;
    for(int i=x;i<=y;i++){
        if(a[i]-a[x]<=d)
            dfs(i,y,z+1);
    }


}

int main(){
    freopen("migrate.in","r",stdin);
    freopen("migrate.out","w",stdout);
   scanf("%d%d",&c,&t);
   while(t--){
    ans=0;
    scanf("%d%d",&n,&d);
    for(int i=1;i<=n;i++){
        scanf("%lld",a+i);
    }
    for(int i=1;i<=n;i++){
        for(int j=i+2;j<=n;j++){
            minn=j-i;
            cut=0;
            dfs(i,j,0);
            if(cut==2)ans++;
        }
    }
    printf("%lld\n",ans);
   }
}




