#include<bits/stdc++.h>
using namespace std;
int n;
long long m;
long long a[500005],q[500005];
bool check(int x,int y){
    long long u=q[y]-q[x]-(a[y]-a[x])*(x-1);
    return u<=m;
}
int main(){
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);                        
    scanf("%d%lld",&n,&m);
    for(int i=1;i<=n;i++){
        scanf("%lld",&a[i]);
    }
    sort(a+1,a+n+1);
    q[1]=0;
    for(int i=2;i<=n;i++){
        q[i]=q[i-1]+(i-1)*(a[i]-a[i-1]);
    }
    int ans=1;
    for(int i=2;i<=n;i++){
        int l=0,r=i;
        while(l<r-1){
            int m=(l+r)/2;
            if(check(m,i)){
                r=m;
            }else{
                l=m;
            }
        }
        ans=max(ans,i-r+1);
    }
    printf("%d\n",ans);
    return 0;
}