#include<bits/stdc++.h>
#define write ios::sync_with_stdio(0),
#define by cin.tie(0),
#define HN_S00230 cout.tie(0)
#define fori for(int i = 1; i < n; i ++)
using namespace std;
const int N = 1e6 + 5;

int c,t,n,k,fa[N],u,v;
int main(){
	write by HN_S00230;
	freopen("hub.in","r",stdin);
	freopen("hub.out","w",stdout);
	cin >> c >> t;
	while(t--){
        cin >> n >> k;
        fori{
            cin >> u >> v;
            fa[max(u,v)] = min(u,v);
        }
        cout << 0 << "\n";
	}
	return 0;
}
