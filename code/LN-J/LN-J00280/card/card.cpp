#include<bits/stdc++.h>
using namespace std;
int n,m,a[500020],b[500020],ans[500020],c[500020];
int main(){
    freopen("card.in","r",stdin);
    freopen("card.out","w",stdout);
    scanf("%d%d",&n,&m);
    for(int i=1;i<=n;i++) scanf("%d",&a[i]);
    for(int i=1;i<=n;i++){
        memset(b,0,sizeof b);
        memset(c,0,sizeof c);
        for(int j=i;j<=n;j++){
            if(b[a[j]]){
                int kg=0;
                for(int k=i;k<j;k++){
                    if(a[j]==a[k]&&c[k]==0)kg=1;
                    if(kg) b[a[k]]=0,c[k]=1;
                }
            }
            b[a[j]]++;
        }
        for(int j=1;j<=m;j++){
            ans[j]+=b[j];
        }
    }
    for(int i=1;i<=m;i++){
        printf("%d ",ans[i]);
    }
}
