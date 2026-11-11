#include <bits/stdc++.h>
using namespace std;

long long n,m,a[200002],ans;

int main(){
    freopen("and.in","r",stdin);
    freopen("and.out","w",stdout);
    scanf("%lld%lld",&n,&m);
    for(int i=1;i<=n;i++){
        scanf("%lld",&a[i]);
    }
    for(int i=1;i<=m;i++){
        for(int j=i+1;j<=n;j++){
            if(a[i]<a[j]){
                swap(a[i],a[j]);
            }
        }
    }
    ans=a[1];
    for(int i=2;i<=m;i++){
        ans=ans&a[i];
    }
    //printf("%d",n);
    printf("%lld",ans);
    return 0;
}

