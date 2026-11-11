#include <bits/stdc++.h>
using namespace std;
#define LL long long
const int N = 5e3+8;

LL n,m,a[N],s[N],ss[N];
int ans = 0;

int main(){
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin >> n >> m;
    for(int i = 1;i <= n;i++){
        cin >> a[i];
    }
    sort(a+1,a+n+1);
    for(int i = 1;i <= n;i++){
        for(int j = 1;j <= n;j++){
            if(j == i) {s[j] = 1e12;continue;}
            s[j] = abs(a[i]-a[j]);
        }
        sort(s+1,s+n+1);
        for(int j = 1;j <= n;j++){
            ss[j] = ss[j-1]+s[j];
        }
        for(int j = 1;j <= n;j++){
            //cout << ss[j] << " ";
            if(ss[j] > m){
                ans = max(ans,j);
                break;
            }
        }
        //cout << "\n";
    }
    cout << ans;
    return 0;
}
