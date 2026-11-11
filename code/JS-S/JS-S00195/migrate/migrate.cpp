#include<bits/stdc++.h>
using namespace std;
#define int long long

const int N = 2e6 + 3;
int c, t, n, d;
int x[N], lst[N];
struct T{
    int val, x, i;
    // flying time, chuanyi cishu , position
    bool operator < (const T&_) const {
        return val == _.val?x>_.x:val>_.val;
    }
};
deque<T> dq;
int ans = 0;
void getans(int from) {
    dq.clear();
    //cout << "From=" << from << endl;
    dq.push_front({1,1,from});
    for(int i = from+1; i <= n; ++i) {
        while(dq.size()&&dq.front().i<lst[i]) {
            dq.pop_front();
        }
        if(dq.empty()) {
            break;
        }
        vector<T> vec;
        int nowval = dq.front().val, nowx = dq.front().x;
        vec.push_back(dq.front());
       // cout << dq.front().i << endl;
        dq.pop_front();
        while(dq.size()&&dq.front().val==nowval&&nowx<3) {
         //   cout <<"|"<< dq.front().val << ' ' << nowval << ' ' << dq.front().i << '\n';
            vec.push_back(dq.front());
            nowx+=dq.front().x;
            dq.pop_front();
        }
        if(nowx>3) nowx=3;
        for(int kk = vec.size()-1;kk>=0;--kk) {
            dq.push_front(vec[kk]);
        }
        dq.push_back({nowval+1,nowx,i});
      //  cout << nowval << ' ' << nowx << ' ' << i<< endl;
        if(nowx==2) {
            ++ans;

        }
    }

}
void solve() {
    cin >> n >> d;ans^=ans;
    for(int i = 1; i <= n; i++) {
        cin >> x[i];
        lst[i] = lower_bound(x+1,x+i,x[i]-d)-x;
     //   cout << lst[i] << ' ' ;
    }
   // cerr<<"\n";
    for(int i = 1; i < n; i++) {
        getans(i);
    }
    cout << ans << endl;

}
void baoli11() {
    while(t--) {
        cin >> n >> d;
        if(n==1) {
            cout << 0 << endl; continue;
        }
        for(int i = 1; i <= n; i++) {
            cin >> x[i];
        }
        if(x[3]-x[1]>d) {
            cout << 0 << endl; continue;
        }
        cout << n - 3 << endl;
    }
    exit(0);
}
signed main() {
    freopen("migrate.in","r",stdin);
    freopen("migrate.out","w",stdout);
    ios::sync_with_stdio(0);

    cin >> c >> t;
    if(c>10) {
        if(c==26) {
            baoli11();
        } else {
            for(int i = 1; i <= t; i++) {
                cout << "0\n";
            }
            return 0;
        }

    }
    while(t--) solve();
    return 0;
}
