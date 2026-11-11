#include<bits/stdc++.h>
using namespace std;
const int maxn=3000;
const int N=5e5+3;
const int INF=0x3f3f;
int c,n,m,d,q;
int f[maxn][maxn];
int w[N];
int a[505][1003],t[505][1003];
int main(){
	freopen("subway.in","r",stdin);
    freopen("subway.out","w",stdout);
   scanf("%d%d%d%d%d",&c,&n,&m,&d,&q);
   memset(f,INF,sizeof(f));
   for(int i=1;i<=m;i++){
      scanf("%d",&w[i]);
   }
   int p;
   for(int i=1;i<=n;i++){
        scanf("%d",&p);
        for(int j=1;j<=p;j++){
            scanf("%d%d",&a[i][j],&t[i][j]);
            f[i+m][j]=t[i][j]+w[j];
       }
   }
   for(int i=1;i<=n+m;i++){
      f[i][i]=0;
   }
   for(int k=1;k<=n+m;k++){
    for(int i=1;i<=n+m;i++){
        for(int j=1;j<=n+m;j++){
              f[i][j]=min(f[i][j],f[i][k]+f[k][j]);
        }
     }
   }
   int x,y;
   while(q--){
    scanf("%d%d",&x,&y);
    printf("%d\n",f[x][y]);
   }
   return 0;
}
//I hope everyone could get great grads!
