#include<bits/stdc++.h>
using namespace std;
int n,m,a[200050],sum[32],ans=0;
bool f[200050][32];
void build(int x,int y){
    int c=1;
    while(y>0){
        if(y&1==1){
            f[x][c]=true;
        }
        sum[c]+=(y&1);
        y>>=1;
        c++;
    }
}
void d(int x){
    for(int i=30;i>=1;i--){
        if(f[x][i]){
            sum[i]--;
            f[x][i]=false;
        }
    }
    a[x]=0;
}
int main(){
    freopen("and.in","r",stdin);
    freopen("and.out","w",stdout);
    memset(f,false,sizeof(f));
    memset(sum,0,sizeof(sum));
    scanf("%d%d",&n,&m);
    for(int i=1;i<=n;i++){
        scanf("%d",&a[i]);
        build(i,a[i]);
    }
    for(int i=30;i>=1;i--){
        if(sum[i]==m){
            for(int j=1;j<=n;j++){
                if(f[j][i]){
                    if(ans==0){
                        ans=a[j];
                    }
                    else{
                        ans&=a[j];
                    }
                }
            }
            printf("%d",ans);
            return 0;
        }
        if(sum[i]>m){
            for(int j=1;j<=n;j++){
                if(!f[j][i])d(j);
            }
        }
    }
    for(int i=1;i<=n;i++){
        if(a[i]>0){
            if(ans==0){
                ans=a[i];
            }
            else{
                ans&=a[i];
            }
        }
    }
    printf("%d",ans);
    return 0;
}
/*
5 3
31 3 1 15 7
*/
