#include <bits/stdc++.h>
using namespace std;
int n,as=1;
long long a[500001],m,s[500001];
int main(){
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);
    cin >>n>>m;
    for(int i=1;i<=n;i++)
        cin >>a[i];
    sort(a+1,a+n+1);
    for(int i=1;i<=n;i++)
        s[i]=s[i-1]+a[i];
    for(int i=n;i>=1;i--)
        if(s[i]+m>=a[i]*i){
            as=i;
            break;
        }
    cout <<as;
    return 0;
}
