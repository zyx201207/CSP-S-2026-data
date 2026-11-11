#include<bits/stdc++.h>
#define Maxn 2000010
#define LL long long
using namespace std;
int c,t,n,b[Maxn];
LL ans;
LL d,a[Maxn];
void free(){
    freopen("migrate.in","r",stdin);
    freopen("migrate.out","w",stdout);
}
bool p(int x){
    for(int i=x+1;i<b[x]-1;i++){
        if(b[i]==b[b[x]-1])return false;
    }
    return true;
}
int main(){
    free();
    scanf("%d%d",&c,&t);
    while(t--){
        scanf("%d%lld",&n,&d);
        ans=0;
        for(int i=1;i<=n;i++)
            scanf("%lld",&a[i]);
        if(c==11||c==12){
            LL h=d/(a[2]-a[1]);
            ans=n-2*h+1;
            if(ans<=0)printf("0\n");
            else printf("%lld\n",ans);
        }
        else{
            for(int i=1;i<=n;i++){
                for(int j=i;j<=n;j++){
                    if(a[j]-a[i]<=d)b[i]=j;
                }
            }
            for(int i=1;i<n;i++){
                if(b[i]!=i&&p(i))ans++;
            }
            printf("%lld\n",ans);
        }
    }
    return 0;
}
