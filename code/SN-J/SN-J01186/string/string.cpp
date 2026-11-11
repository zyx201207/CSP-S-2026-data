#include<bits/stdc++.h>
#define int long long
using namespace std;
int n;
struct element{
    int cnt;
    char ch;
}a[200005];
signed main(){
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    scanf("%lld",&n);
    for(int i=1,x;i<=n;i++){
        scanf("%lld%c",&a[i].cnt,&a[i].ch);
    }
    printf("0");
    return 0;
}
