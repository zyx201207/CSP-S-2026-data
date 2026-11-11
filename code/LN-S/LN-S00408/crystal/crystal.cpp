#include<bits/stdc++.h>
using namespace std;
#define int long long
inline int read(){
    int x = 0, f = 1;
    char ch = getchar();
    while(ch < '0' || ch > '9'){
        if(ch == '-')f = -1;
        ch = getchar();
    }
    while(ch >= '0' && ch <= '9'){
        x = (x<<3)+(x<<1)+ch-'0';
        ch = getchar();
    }
    return x*f;
}
const int N = 5e5+5;
int n,m,a[N];
signed main(){
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);

    n = read(), m =read();
    for(int i = 1; i <= n; i++)a[i] = read();
    sort(a+1,a+n+1);
    int i = 1,cnt=0,maxn=-1e9;
    for(int j = 2; j <= n; j++){
        while(cnt + (a[j]-a[j-1])*(j-i)>m){
            cnt -= (a[j-1]-a[i]);
            i++;
        }
        cnt += (a[j]-a[j-1])*(j-i);
        maxn = max(maxn, j-i+1);
    }
    cout << maxn;

    fclose(stdin);
    fclose(stdout);
    return 0;
}
