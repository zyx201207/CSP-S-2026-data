#include <bits/stdc++.h>
using namespace std;
int n,mx;
long long m,a[500005],now,s[500005];
bool k=0;
int main(){
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);
    scanf("%d %lld",&n,&m);
    for(int i=1;i<=n;i++){
        scanf("%lld",&a[i]);
    }
    sort(a+1,a+n);
    if(n<=5000){
        for(int j=1;j<n-mx;j++){
            now = 0;
            k = 0;
            for(int i=j;i<n;i++){
                now+=i*(a[i+1]-a[i]);
                if(now>m){
                    mx = max(mx,i-j+1);
                    k = 1;
                    break;
                }
            }
            if(k==0) mx = max(mx,n-j);
        }
        printf("%d",mx);
    }else{
        for(int i=1;i<n;i++){
            now+=i*(a[i+1]-a[i]);
            if(now>m){
                mx = max(mx,i);
                k = 1;
                break;
            }
        }
        if(k==0) mx = n;
        printf("%d",mx);
    }
    return 0;
}
