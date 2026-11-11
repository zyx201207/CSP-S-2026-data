#include<bits/stdc++.h>
using namespace std;
const int N = 2e5+10;
typedef long long LL;
int n,m;
LL a[N],ans;
bool nav[N];
int main(){
    freopen("and.in","r",stdin);
    freopen("and.out","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0),cout.tie(0);
    cin >> n >> m;
    for(int i = 1;i <= n;i++)   cin >> a[i];
    for(int j = 31;j >= 0;j--){
        int cnt = 0;
        for(int i = 1;i <= n;i++){
            if(nav[i])  continue;
            cnt += (a[i]>>j) & 1;
        }
        if(cnt >= m){
            ans |= (1<<j);
            for(int i = 1;i <= n;i++){
                if(nav[i])  continue;
                if(((a[i]>>j) & 1) != 1)  nav[i] = 1;
            }
        }
    }
    cout << ans;
    return 0;
}