#include<bits/stdc++.h>
using namespace std;
#define int long long

const int N = 1e6 + 10;
int a[N];
int n, m;
bool f[N];
int p[N];
int cd[N];
int cnt[N];
int tot = 0;
signed main(){
	freopen("card.in", "r", stdin);
	freopen("card.out", "w", stdout);
    cin >> n >> m;
    for(int i = 1;i <= n;i++){
        cin >> a[i];
    }
    for(int i = 1;i <= n;i++){
        memset(f, false, sizeof(p));
        memset(p, 0, sizeof(p));
        tot = 0;
        for(int c = i;c <= n;c++){
            if(f[a[c]] == false){
                cd[++tot] = a[c];    
                f[a[c]] = true;
                p[a[c]] = tot;
            } else {
                for(int j = p[a[c]] + 1;j <= tot;j++){
					int node = cd[j];
                    f[node] = false;
                    p[node] = 0;
                }
                tot = p[a[c]];
            }
        }
        //for(int j = 1;j <= tot;j++){
		//	cout << cd[
		//}
        for(int c = 1;c <= m;c++){
            if(f[c]){
                cnt[c]++;
            }
        }
    }
    for(int i = 1;i <= m;i++){
        cout << cnt[i] << ' ';
    }
    return 0;
}
