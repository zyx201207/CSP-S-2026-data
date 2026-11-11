#include<bits/stdc++.h>
#define endl '\n'
#define pii pair<int,int>
using ll = long long;
using namespace std;
constexpr int N = 2*114514;
ll n,m,mx=-1;
ll a[N],px[N],ex[N],ton[6];
void dfs(int t,int k,ll h){
    if(t == 0)mx = max(mx,h);
    else for(int i = k+1 ; i <=n ; i++){
        int x = h & a[i];
        dfs(t-1,i,x);
    }
    return ;
}
int main(){
    freopen("and.in","r",stdin);
    freopen("and.out","w",stdout);
    bool f = 1,pl = 1;
    cin.tie(0)->sync_with_stdio(0);
    cin >> n >> m;
    for(int i = 1 ; i <= n ; i++){
        cin >> a[i];
        if(a[i] != i-1)f = 0;
        if(a[i] >= 4)pl=0;
        if(pl)ton[a[i]]++;
    }
    sort(a+1,a+n+1);
    if(m == 1){
        cout << a[n] << endl;
        return 0;
    }
    if(m == n){
            int sum = a[1];
        for(int i = 2 ; i <= n ; i++){
            sum = sum & a[i];
        }
    cout << sum << endl;
    return 0;
    }
    if(m == 2){
        ll maxn = -1;
        for(int i = 1 ; i <= n ; i++){
            for(int j = i+1 ; j <= n ; j++){
                maxn = max(maxn,a[i]&a[j]);
            }
        }
        cout << maxn << endl;
        return 0;
    }
    if(n <= 20){
        dfs(m,0, 4611686018410610687);
        cout << mx << endl;
        return 0;
    }
    else if(m == n-1){
        px[1] = a[1];px[0] = 4611686018410610687;
        for(int i = 2 ; i <= n ; i++){
            px[i] = px[i-1]&a[i];
        }
        ex[n] = a[n] ; ex[n+1] = 4611686018410610687;
        for(int i = n - 1 ; i >= 1 ; i--){
            ex[i] = ex[i+1]&a[i];
        }
        for(int i = 1 ; i <= n ; i++){
            mx = max(mx,ex[i+1]&px[i-1]);
        }
        cout << mx << endl;
        return 0;
    }
    else if(f == 1){
        int sum = 4611686018410610687;
        for(int i = n ; i > n-m ; i--){
            sum = sum & a[i];
        }
        cout << sum << endl;
        return 0;
    }
    else if(pl == 1){
        int sum = 0;
        if(m <= ton[3])sum=3;
        else if(m <= ton[2]+ton[3])sum=2;
        else if(m <= ton[1]+ton[2]+ton[3])sum=1;
        else sum = 0;
        cout << sum << endl;
        return 0;
    }
    else{
        int sum = 4611686018410610687;
        sum = a[n-m+1];
        cout << sum << endl;
        return 0;
    }
    return 0;
}
