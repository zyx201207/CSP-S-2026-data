#include<bits/stdc++.h>
using namespace std;
long long n,l,ans,gcd,a[200001];
char s[2000001],s1[200001];
int main(){
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    scanf("%lld",&n);
    for (int i=1;i<=n;i++)
    {
        scanf("%lld",&a[i]);
        if (i==1)
            gcd=a[i];
        else
            gcd=__gcd(gcd,a[i]);
        cin>>s1[i];
    }
    for (int i=1;i<=n;i++){
        for (int j=1;j<=a[i]/gcd;j++){
            s[l]=s1[i];
            l++;
        }
    }
    for (int i=0;i<l/2;i++){
        if (s[i]!=s[l-1-i])
            ans++;
    }
    printf("%lld",ans*gcd);
    return 0;
}
