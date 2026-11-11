#include <bits/stdc++.h>
using namespace std;

long long n,a[200002];
char c[200002];
long long sum=0;

int main(){
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    scanf("%lld",&n);
    for(int i=1;i<=n;i++){
        scanf("%lld %c",&a[i],&c[i]);
    }

    long long l=1,r=n+1-l;

    while(l<r){
        if(a[l]>a[r]){
            if(c[l]!=c[r]){
                sum+=a[l]-a[r];
            }
            a[l]-=a[r];
            r--;
        }
        else if(a[l]<a[r]){
            if(c[l]!=c[r]){
                sum+=a[r]-a[l];
            }
            a[r]-=a[l];
            l++;
        }
        else {
            if(c[l]!=c[r]){
                sum+=a[r];
            }
            r--;
            l++;
        }
    }
    printf("%lld",sum);
    return 0;
}

