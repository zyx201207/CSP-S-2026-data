#include<iostream>
#include<vector>
typedef long long ll;
const int N=2e6+114;
int t,c,n;
ll d,x[N];

void solve(){
    scanf("%d%lld",&n,&d);
    for(int i=1;i<=n;i++)scanf("%lld",x+i);

    int ans=0;
    for(int i=4;i<=n;i++){
        if(x[i]-x[i-2]<=d)++ans;
    }
 
    printf("%d\n",ans);
}

int main(){
    freopen("migrate.in","r",stdin);
    freopen("migrate.out","w",stdout);

    scanf("%d%d",&c,&t);
    while(t--)solve();

    return 0;
}
