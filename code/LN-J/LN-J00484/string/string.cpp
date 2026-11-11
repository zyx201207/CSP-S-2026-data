#include <bits/stdc++.h>
using namespace std;
const int maxn = 2e5 + 10;
int n;
struct k{
    long long n;
    char c;
}a[maxn];
int main(){
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    scanf("%d",&n);
    for(int i = 1 ; i <= n ; i++)
        scanf("%lld %c",&a[i].n,&a[i].c);

    string tmp = "";
    for(int i = 1 ; i <= n ; i++)
        for(int j = 1 ; j <= a[i].n ; j++)
            tmp += a[i].c;

    long long ans = 0;
    for(int i = 0 ;i <= tmp.size()/2 ; i++)
        if(tmp[i] != tmp[tmp.size()-1-i])
            ans ++;

    printf("%lld",ans);
    return 0;
}

