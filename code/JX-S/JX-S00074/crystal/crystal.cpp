#include<bits/stdc++.h>
using namespace std;
typedef long long LL;
const int N=5*1e5;
LL n,m;
LL a[N];
int main(){
    //freopen("crystal.in","r",stdin);
    //freopen("crystal.out","w",stdout);
    scanf("%d%d",&n,&m);
    for(LL i=0;i<n;i++){
        scanf("%d",&a[i]);
    }
    LL k,ans=1;
    for(LL i=0;i<n-1;i++){
        k=max(a[i+1],a[i])-min(a[i+1],a[i]);
        k=k*(i+1);
        if(m>k){
            m=m-k;
            ans++;
        }
        else{
            break;
        }
    }
    printf("%d",ans);
    return 0;
}
