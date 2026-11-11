#include<bits/stdc++.h>
using namespace std;
#define int long long
const int N = 2e5+5;
const int inf = 0x3f3f3f3f;

int read(){
    int x = 0,f = 1;char c = getchar_unlocked();
    while(!isdigit(c)){if(c == '-')f = -1;c = getchar_unlocked();}
    while(isdigit(c)){x = x*10 + c-'0';c = getchar_unlocked();}
    return x*f;
}

int a[N],ma = -1,n,m,cnt = 0,f[N];

signed main(){
    freopen("and.in","r",stdin);
    freopen("and.out","w",stdout);
    n = read(),m = read();
    for(int i = 1;i <= n;i++)a[i] = read();
    if(m == 1){
        for(int i = 1;i <= n;i++)ma = max(ma,a[i]);
        cout << ma;
        return 0;
    }
    if(m == 2){
        for(int i = 1;i < n;i++)
            for(int j = i+1;j <= n;j++)
                ma = max(ma,(a[i]&a[j]));
        cout << ma;
        return 0;
    }
    if(m == n){
        int sum = a[1];
        for(int i = 2;i <= n;i++)sum = (sum & a[i]);
        cout << sum;
        return 0;
    }

    for(int i = 0;i <= m;i++)f[i] = 0;
    f[0] = (1<<30);
    f[1] = a[1];
    for(int i = 1;i <= n;i++){
        for(int j = m+1;j >= 1;j--)
            f[j] = max((f[j-1]&a[i]),f[j]);
        ma = max(ma,f[m+1]);
    }
    cout << ma << endl;
    fclose(stdin);
    fclose(stdout);
    return 0;
}
