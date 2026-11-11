/*#include <bits/stdc++.h>
using namespace std;
int n,cnt[200005],x,sum;
char a[200005],y;
int main(){
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    cin >> n;
    for (int i = 1;i <= n;i++){
        cin >> x >> y;
        cnt[i] = x;
        a[i] = y;
        sum += x;
    }
    int sum1 = 0,fen,s,sa;
    for (int i = 1;i <= n;i++){
        if (sum1 += cnt[i] >= sum / 2){
            if (sum1 != sum / 2){
                fen = i;
                s = sum1 - sum;
                cout << s;
                sa = a[i];
            }
        }
    }
    if (sum1 != sum / 2){
        int t;
        char ta;
        cnt[fen] -= s;
        t = cnt[fen + 1];
        ta = a[fen + 1];
        for (int i = fen + 1;i <= n;i++){
            cnt[i] = t;
            a[i] = ta;
            t = cnt[i + 1];
            ta = a[i + 1];
        }
        for (int i = 1;i <= n;i++){
            cout << cnt[i] << ' ' << a[i] << endl;
        }
    }
}*/
#include <bits/stdc++.h>
using namespace std;
int n,sum,ans;
char a[100000000];
int main(){
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    cin >> n;
    for (int i = 1;i <= n;i++){
        int x;
        char y;
        cin >> x >> y;
        for (int i = sum + 1;i <= sum + x;i++){
            a[i] = y;
        }
        sum += x;
    }
    for (int i = 1;i <= sum / 2;i++){
        if (a[i] != a[sum - i + 1]){
            ans++;
        }
    }
    cout << ans;
}
