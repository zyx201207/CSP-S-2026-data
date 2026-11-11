#include<bits/stdc++.h>
#define ll long long
using namespace std;
int c,t;
const int MAX = 2e6 + 5;
int minn = MAX;
int st[MAX];
ll a[MAX];
int n;
long d;
inline void dfs(int u,int last){
    if(a[u] - a[last] > d) return ;
    if(u == n + 1){
        int ss = 0;
        for(int i = 1;i <= n;i++) if(st[i]) ss++;
        if(ss) minn = min(minn,ss);
        return ;
    }

    st[u] = 0;
    dfs(u + 1,last);

    for(int i = u + 1;i <= n;i++){
        st[u] = i;
        dfs(u + 1,i);
        st[u] = 0;

    }

}
int main(){
    freopen("migrate.in","r",stdin);
    freopen("migrate.out","w",stdout);

    cin >> c >> t;
    for(int i = 1;i <= t;i++){
        cin >> n >> d;
        bool flag = true;
        for(int i = 1;i <= n;i++){
            cin >> a[i];
            if(i > 2){
                if((!(a[i] - a[i - 1]) == (a[i - 1] - a[i - 2]))) flag = false;
            }
        }
        if(flag){
            if(a[2] - a[1] < d) cout << 0 << '\n';
            else if((n / (d / (a[2] - a[1]))) * (a[2] - a[1]) == a[n] - a[1]) cout << 1 << '\n';
            else cout << 2 << '\n';
        }
        else{
            dfs(1,0);
            cout << minn << '\n';
        }

    }

    return 0;
}
