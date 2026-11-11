#include<bits/stdc++.h>
using namespace std;
const int N=2000010;
int c,t;
int n;
long long d;
long long x[N];
int num[N];
void solve(){
    memset(num,0,sizeof(num));
    num[1]=1;
    for(int i=2;i<=n;i++){
        int j=i;
        while(j>=1 and x[i]-x[j]<=d){
            num[i]+=1;
            j--;
        }
    }
    int ans=0;
    for(int i=1;i<=n;i++){
        if(num[i]==3){
            ans++;
        }
    }
    printf("%d\n",ans-1);
}
int main(){
    freopen("migrate.in","r",stdin);
    freopen("migrate.out","w",stdout);
    scanf("%d%d",&c,&t);
    while(t--){
        scanf("%d%lld",&n,&d);
        for(int i=1;i<=n;i++){
            scanf("%lld",&x[i]);
        }
        solve();
    }
    return 0;
}
