#include<bits/stdc++.h>
using namespace std;
#define int long long
const int N = 5e5+5;
const int inf = 0x3f3f3f3f;

int read(){
    int x = 0,f = 1;char c = getchar_unlocked();
    while(!isdigit(c)){if(c == '-')f = -1;c = getchar_unlocked();}
    while(isdigit(c)){x = x*10 + c-'0';c = getchar_unlocked();}
    return x*f;
}

int a[N],q[N],n,m;

bool check(int k,int i){
    if(a[i]*(i-k)-q[i-1]+q[k-1] <= m)return 1;
    return 0;
}

signed main(){
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);
    n = read(),m = read();
    for(int i = 1;i <= n;i++)a[i] = read();
    sort(a+1,a+n+1);
    for(int i = 1;i <= n;i++)q[i] = q[i-1]+a[i];
    int ma = -1;
    for(int i = 1;i <= n;i++){
        int l = 1,r = i,mid;
        while(l < r){
            mid = floor((l+r)/2.0);
            if(check(mid,i))r = mid;
            else l = mid+1;
            //cout << l << " " << r << " " <<  mid  << " " << i << " ";
        }
        ma = max(i-l+1,ma);
        //cout << i-l+1 << "\n";
    }
    cout << ma;
    fclose(stdin);
    fclose(stdout);
    return 0;
}
