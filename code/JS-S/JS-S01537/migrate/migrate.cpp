#include<bits/stdc++.h>
#define ll long long
using namespace std;
ll a[2000010];
int t,n,d;
bool check(int x,int y){
    if(y-x==2*d-1&&a[y]-a[x]<d*(y-x))  return true;
    return false;
}
int main(){
    freopen("migrate.in","r",stdin);
    freopen("migrate.out","w",stdout);
    scanf("%d",&t);
    scanf("%d",&t);
    while(t--){
        ll sum=0;
        scanf("%d%d",&n,&d);
        for(int i=1;i<=n;i++)   scanf("%lld",&a[i]);
        for(int i=1;i<=n;i++){
            for(int j=i+1;j<=n;j++)
                if(check(i,j))  sum++;
        }
       printf("%lld\n",sum);
    }
    return 0;
}
//rp++
