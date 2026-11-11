#include<cstdio>
const int N=5e5+10,M=3e5+10;
int a[N];
int pre[M];
//int tr[M][N];
int stk[N],tt=0;
int ans[M];
int main(){//brute
    freopen("card.in","r",stdin);
    freopen("card.out","w",stdout);
    int n,m;scanf("%d%d",&n,&m);
    for(int i=1;i<=n;i++){
        scanf("%d",&a[i]);
    }
    if(m==2){//sp
        for(int i=1;i<=n;i++){
            if(a[n]){
                ans[a[n]]++;
            }
            if(a[i]!=a[n]){
                ans[a[i]]++;
            }
        }
        for(int i=1;i<=m;i++){
            printf("%d ",ans[i]);
        }
        return 0;
    }
    for(int i=1;i<=n;i++){
        tt=0;
        for(int j=1;j<=m;j++)pre[j]=0;
        for(int j=i;j<=n;j++){
            if(pre[a[j]]){
                while(tt>pre[a[j]])pre[stk[tt--]]=0;
            }else{
                stk[++tt]=a[j];
                pre[a[j]]=tt;
            }
        }
        for(int j=1;j<=tt;j++){
            ans[stk[j]]++;
        }
    }
    for(int i=1;i<=m;i++){
        printf("%d ",ans[i]);
    }
    return 0;
}
