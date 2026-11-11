#include<bits/stdc++.h>
using namespace std;
long long n;
long long a[200010];
char c[200010];
string s;
int main(){
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    scanf("%lld",&n);
    for(long long i=1;i<=n;i++){
        scanf("%lld",&a[i]);
        scanf("%c",&c[i]);
    }
    for(long long i=1;i<=n;i++){
        if(c[i]==c[i+1])cout<<0;
    }
    return 0;
}
