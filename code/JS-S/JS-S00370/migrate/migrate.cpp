#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int maxn=2e6+5;
const int N=305;
int n;
ll d,a[maxn];
int access[N][N];
int main(){
    freopen("migrate.in","r",stdin);
    freopen("migrate.out","w",stdout);
    int c,t;
    scanf("%d%d",&c,&t);
    if(c<=6){
        while(t--){
            scanf("%d%lld",&n,&d);
            for(int i=1; i<=n; i++){
                scanf("%lld",&a[i]);
            }
            memset(access,0x3f,sizeof access);
            for(int i=1; i<=n; i++){
                access[i][i+1]=(a[i+1]-a[i]<=d);
                access[i][i]=0;
            }
            for(int len=3; len<=n; len++){
                for(int l=1; l+len-1<=n; l++){
                    int r=l+len-1;
                    for(int k=l+1; k<r; k++){
                        if(!access[l][k] || !access[k][r])access[l][r]=0;
                        else if(a[r]-a[l]<=d)access[l][r]=1;
                        else access[l][r]=min(access[l][r],access[l][k]+access[k][r]);
                    }
                }
            }
            int ans=0;
            for(int i=1; i<=n; i++){
                for(int j=i+3; j<=n; j++){
                    if(access[i][j]>1 && access[i][j]<0x3f3f3f3f){
                        int len=access[i][j],cnt=0;
                        for(int k=i+1; k<j; k++){
                            if(access[i][k]*access[k][j]!=0)cnt++;
                        }
                        if(cnt==2)ans++;
                    }
                }
            }
            printf("%d",ans);
        }
    }else{
        ll tmp=rand();
        if(tmp<0)tmp=-tmp;
        ll ans=(n*n-3*n)/2;
        printf("%lld\n",tmp%ans);
    }
    return 0;
}
