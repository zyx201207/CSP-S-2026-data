#include <bits/stdc++.h>
using namespace std;
const int N=500525;
int n,j=2;
long long m,a[N],c[N],ans=-33550336;
void dfs(int x,int y){
    long long sum=0;
    int an=1;
    for(int i=x;i<=y;i++){
        sum+=c[i]*an;
        an++;
        if(sum<=m){
            if(ans<an){
                ans=an;
            }
        }else{
            while(sum>m){
                sum-=(a[i]-a[j-1]);
                j++;
                an--;
            }
        }
    }
    return;
}
int main(){
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);
    scanf("%d%lld",&n,&m);
    for(int i=1;i<=n;i++){
        scanf("%lld",&a[i]);
    }
    sort(a+1,a+n+1);
    c[1]=0;
    for(int i=2;i<=n;i++){
        c[i]=a[i]-a[i-1];
    }
    dfs(2,n);
    printf("%lld",ans);
    return 0;
}
