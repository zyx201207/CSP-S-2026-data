#include<bits/stdc++.h>
using namespace std;
typedef unsigned long long ull;
const int inf = 1e7+10;
char ch[inf];
int main(){
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    ull n,a,flag = 0;
    char c;
    scanf("%llu",&n);
    for(ull i=1;i<=n;i++){
        scanf("%llu %c",&a,&c);
        for(ull j=1;j<=a;j++){
            ch[flag] = c;
            flag++;
        }
    } ull l = 0,r = flag-1,ans = 0;
    while(l < r){
        if(ch[l] != ch[r]){
            ans++;
        } l++;
        r--;
    } printf("%llu",ans);
    return 0;
}
