/*g++ migrate.cpp -o migrate -std=c++14 -Wall -Wextra -fsanitize=undefined,address*/
//g++ default.cpp -o default -std=c++14 -static -O2
#include<bits/stdc++.h>
using ll = long long;
using namespace std;
const int N = 2e6+10, mod = 998244353;
ll n, d, a[N], c, t;
int main(){
    freopen("migrate.in","r",stdin);
    freopen("migrate.out","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin>>c>>t;
    while(t--){
        cin>>n>>d;
        for(int i = 1; i <= n; i++)cin>>a[i];
        ll ans = 0;
        for(int i = 1; i < n-1; i++){
            for(int j = i+2; j <= n; j++){
                priority_queue<pair<ll,int>> q;
                q.push({a[i],0});
                ll cnt = 0;
                bool flag = 0;
                int minl = mod;
                while(!q.empty()){
                    ll cur = q.top().first;
                    int len = q.top().second;
                    q.pop();
                    if(cur == a[j]){
                        if(flag == 0){
                            flag = 1;
                            cnt++;
                            minl = len;
                        }
                        else if(flag == 1){
                            if(len == minl)cnt++;
                        }
                        continue;
                    }
                    if(cnt > 2 || len > minl)continue;
                    int l = upper_bound(a+i,a+j+1,cur) - a;
                    int r = upper_bound(a+i,a+j+1,max(cur+d,a[j])) - a;
                    if(a[r] > cur + d)r--;
                    //cout<<cur<<' '<<a[l]<<' '<<a[r]<<endl;
                    for(int k = l; k <= r; k++){
                        q.push({a[k],len + 1});
                    }
                }
                cout<<"i:"<<i<<" j:"<<j<<" len:"<<minl<<endl;
                if(cnt == 2){
                    ans++;
                    cout<<i<<' '<<j<<endl;
                }
            }
        }
        cout<<ans<<endl;
    }
    return 0;
}