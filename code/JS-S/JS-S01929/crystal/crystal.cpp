#include<bits/stdc++.h>
using namespace std;
#define int long long
const int N = 5e5 + 5;
int n,m,a[N],ans;
signed main(){
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);
    ios::sync_with_stdio(0);cin.tie(0),cout.tie(0);
    cin>>n>>m;
    bool flag = false;
    for(int i=1;i<=n;i++){
        cin>>a[i];
        if(a[i] == i){
            flag = true;
        }
    }

    if(flag){
        int num = 0;
        for(int i=1;i<=n;i++){
            num += i;
            if(num >= m){
                cout<<i;
                return 0;
            }
        }
    }
    sort(a+1,a+n+1);
    int tmp = n - 1;
    int l = 1;
    while(tmp >= 0){
        int r = l + tmp;
        int cnt = 0;
        for(int i=l;i<=r;i++){
            cnt += (a[r] - a[i]);
        }
        if(cnt <= m){
            ans = r - l + 1;
            break;
        }
        if(r == n){
            l = 0;
            tmp --;
        }
        l ++;
    }
    cout<<ans<<endl;
    return 0;
}
