#include<bits/stdc++.h>
using namespace std;
#define F(i,l,r) for(int i=(l);i<=(r);i++)
#define int long long
#define pb push_back
const int num=2000005;
const int inf = 1e15;
int n,d,mx = 0, ans,co[num];
void cnt(int x,int y,int c){
    if(c>mx)return ;
    if(x==y){
        if(c==mx){
            ans++;
        }
        else{
            mx = c;
            ans = 1;
        }
            return ;
    }
    for (int i = x + 1; i <= y;i++){
        if(co[i]-co[x]<=d){
            cnt(i, y, c + 1);
        }
        else
            break;
    }
}
bool ck(int x,int y){
    mx = inf;
    ans = 0;
    cnt(x, y, 0);
    if(ans==2)
        return 1;
    return 0;
}
void solve(){
    cin >> n >> d;
    F(i, 1, n)
        cin >> co[i];
    int ans = 0;
    F(i, 1, n)
    F(j, i + 1, n) if (ck(i, j)) ans++;
    cout << ans << endl;
}
signed main(){
    freopen("migrate.in","r",stdin);
    freopen("migrate.out","w",stdout);
    ios::sync_with_stdio(false);
    cin.tie(0);cout.tie(0);
    int C, T;
    cin >> C >> T;
    while(T--)
        solve();
}