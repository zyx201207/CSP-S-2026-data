#include <bits/stdc++.h>
using namespace std;
#define ll long long
const int MAXN = 5e5 + 1;
ll n,m;
ll a[MAXN];
ll sum = 0, ans = 0;
ll cnt=0;
int main(){
    freopen("crystal.in", "r", stdin);
    freopen("crystal.out", "w", stdout);
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> n >> m;
    cin >> a[1];
    int diff;
    bool flag=true; //是否为等差数列 (特殊性质A/B)

    for(int i = 2; i <= n; i++){
        cin >> a[i];
        if(i == 2) diff = a[i] - a[i-1];
        if(a[i] - a[i-1] != diff){
            flag = false;
        }
    }
    if(flag && diff == 1){//特殊性质 求和公式/求根公式O(1)
        cout << min(n, (ll)(sqrt(8 * diff * m + diff * diff) - diff) / 2);
        return 0;
    }
    sort(a+1, a+n+1, greater<int>());

    for(int i = 1; i <= n; i++){
        sum = 0; cnt = 0;
        for(int j = i; j <= n; j++){
            //cout<<j<<" ";
            sum+=abs(a[i]-a[j]);
            if(sum > m){
                break;
            }
            else cnt++;
        }
        //printf("%d. %d\n",i,cnt);
        ans = max(ans, cnt);
    }
    cout << ans << endl;

    /*test
    fcloseall();
    freopen("crystal3.ans","r",stdin);
    ll z; cin>>z;
    printf("answer: %d", z);
    */
    return 0;
}
