#include<bits/stdc++.h>
using namespace std;
int a[200010][31];
int p[200010];
int o[200010];
int po[31];
int top,t;
long long ans;
int main(){
    freopen("and.in","r",stdin);
    freopen("and.out","w",stdout);
    int n,m,x,l;
    scanf("%d%d",&n,&m);
    po[0]=1;
    for(int i=1;i<=30;i++) po[i]=po[i-1]*2;
    for(int i=1;i<=n;i++){
        scanf("%d",&x);
        l=0;
        while(x){
            a[i][l++]=x&1;
            x/=2;
        }
    }
    for(int i=30;i>=0;i--){
        l=0;
        top=0;
        for(int j=1;j<=n;j++){
            if(a[j][i]==1){
                l++;
                p[++top]=j;
            }
        }
        if(l>m){
            for(int k=i;k>=0;k--){
                int u=0;
                for(int q=1;q<=l;q++){
                    if(a[p[q]][k]==1){
                        u++;
                        o[++t]=p[q];
                    }
                }
                if(u>m){
                    ans+=po[k];
                    for(int b=1;b<=t;b++)  p[i]=o[i];
                    top=t;
                }else  if(u==m){
                    for(int b=k;b>=0;b--){
                        int y=0;
                        for(int g=1;g<=m;g++){
                            if(a[o[g]][b]==1)  y++;
                        }
                        if(y==m){
                            ans+=po[b];
                        }
                    }
                    break;
                }
                for(int j=t;j>=1;j--)  o[t--]=0;
            }
            break;
        }else  if(l==m){
            for(int k=i;k>=0;k--){
                int u=0;
                for(int q=1;q<=m;q++){
                    if(a[p[q]][k]==1)  u++;
                }
                if(u==m)  ans+=po[k];
            }
            break;
        }
        for(int j=top;j>=1;j--)
            p[top--]=0;
    }
    cout<<ans;
}
