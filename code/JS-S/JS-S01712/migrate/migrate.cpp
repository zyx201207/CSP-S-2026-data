#include<bits/stdc++.h>
using namespace std;
typedef long long LL;
const int N=5010;
int C,T;
int n,p;
LL a[N],cnt[N][N];
LL ans;
int main(){
    freopen("migrate.in","r",stdin);
    freopen("migrate.out","w",stdout);
    scanf("%d%d",&C,&T);
    while(T--){
     //   memset(cnt,-1,sizeof(cnt));
        ans=0;
        scanf("%d%d",&n,&p);
        for(int i=1;i<=n;i++)scanf("%d",&a[i]);
        for(int i=n;i>=2;i--)a[i]-=a[i-1];
        for(int i=1;i<n;i++){
            LL k=(LL)a[i+1];
            for(int j=i+1;j<=n;j++){
                if(a[j]>p)break;
                else{
                    while(k<=p){
                        j++;
                        k+=a[j];
                        cnt[i][j]=cnt[i][j-1]+1;
                        if(cnt[i][j]>2)break;
                    }
                    if(cnt[i][j]==2){
                        ans++;
                        break;
                    }
                    else if(cnt[i][j]>2)break;
                }

            }
        }
        printf("%lld\n",ans);
    }
    return 0;
}
