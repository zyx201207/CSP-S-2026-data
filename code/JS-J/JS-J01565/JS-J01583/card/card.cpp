#include<bits/stdc++.h>
#define endl '\n'
#define pii pair<int,int>
using ll = long long;
using namespace std;
constexpr int N = 5*114514;
int n,m,a[N],f[N],ton[N],last=-1,p[N],s;
int main(){
    freopen("card.in","r",stdin);
    freopen("card.out","w",stdout);
    cin.tie(0)->sync_with_stdio(0);
    cin >> n >> m;
    for(int i = 1 ; i <= n ; i++){
        cin >> a[i];
    }
    int cnt = 0,i=1;
    while(i <= n){
        if(a[i] != last){
        p[a[i]] = ++cnt;
        s++;
        last = a[i];
        }
        else{
            i++;
        }
    }
    for(int i = 1 ; i <= m ; i++){
        if(p[i] == 0)cout << 0 << ' ';
        else cout << s + 1 - p[i] << ' ';
    }
    cout << endl;
    return 0;
}
