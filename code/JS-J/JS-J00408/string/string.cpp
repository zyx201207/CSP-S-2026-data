#include<iostream>
#include<algorithm>
#include<string>
#define int unsigned long long
using namespace std;
int n;
const int N = 200010;
int a[N];
char c[N];
char s;
bool flag = true;
int sum , mid , ans, cnt;
string q = "", p = "";
signed main(){
    freopen("string.in", "r", stdin);
    freopen("string.out", "w", stdout);
    cin >> n;
    for(int i = 1; i <= n; i++){
        cin >> a[i] >> c[i];
        sum += a[i];
        for(int j = 1; j <= a[i]; j++) p += c[i];
        if(i == 1) s = c[i];
        else if(s != c[i]) flag = false;
    }
    if(flag){
        cout << "0";
        return 0;
    }
    if(sum % 2 == 0) mid = sum / 2;
    else mid = sum / 2 + 1;
    for(int i = 1; i <= n; i++){
        for(int j = 1; j <= a[i]; j++){
            if(q.length() == mid) break;
            else q += c[i];
        }
    }
    reverse(q.begin(), q.end());
    for(int i = mid + 1; i <= p.length(); i++) if(p[i] != q[++cnt]) ans++;
    cout << ans;
}
