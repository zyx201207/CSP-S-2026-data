#include<bits/stdc++.h>
using namespace std;
#define int long long
const int N = 5 * 114514;
int n,m,cnt,ans;
struct node{
    int p;
    int c;
    int id;
}b[N];
int a[N],s[N];
bool check(int x,int d,int p){
    if(p * x - s[d - 1] + s[d - x - 1] <= m) return 1;
    return 0;
}
signed main(){
    freopen("crystal.in","r",stdin);

    freopen("crystal.out","w",stdout);
    cin>>n>>m;
    for(int i = 1;i <= n;i ++ ){
        cin>> a[i];
    }
    sort(a + 1,a + n + 1);
    a[0] = LONG_LONG_MAX;
    for(int i = 1;i <= n;i ++ ){
        if(a[i] == a[i - 1]){
            b[cnt].c++;
        }
        else{
            cnt++;
            b[cnt].c = 1;
            b[cnt].id = i;
            b[cnt].p = a[i];
        }
        s[i] = s[i - 1] + a[i];
    }
    for(int i = 1;i <= cnt;i ++ ){
        int lft = 0,rgt = b[i].id - 1;
        int res = 0;
        while(lft <= rgt){
            int mid = lft + rgt >> 1;
            if(check(mid,b[i].id,b[i].p)){
                res = mid;
                lft = mid + 1;
            }
            else{
                rgt = mid - 1;
            }
        }
        // cerr << b[i].p << " " << b[i].id << " " << res << " " << b[i].c << endl;
        ans = max(ans,res + b[i].c);
    }
    cout << ans << endl;
    return 0;
}
// wo yi jing gao 2 le
// neng ying ma