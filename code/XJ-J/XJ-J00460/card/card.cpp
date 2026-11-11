#include<bits/stdc++.h>
#define fast ios::sync_with_stdio(false),cin.tie(0);
#define int long long
using namespace std;
int a[500010],t[500010];
int buk[500010],ans[300010];
signed main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	fast;
	int n, m;
	cin >> n >> m;
	for(int i = 1; i <= n; i++){
		cin >> a[i];
	}
	for(int i = 1; i <= n; i++){//n games
		memset(t,-1,sizeof(t));
		memset(buk,-1,sizeof(buk));
		int idx = 1;
		for(int j = i; j <= n; j++){//n cards
			if(buk[a[j]]==0){
				t[idx++] = a[j];
				buk[a[j]] = 1;
			}else{
				for(int k = 1; k <= idx-1; k++){//take away
					buk[t[k]]=0;
					t[k] = -1;
				}
				t[idx++] = a[j];//put up
				buk[a[j]] = 1;
			}
		}
		for(int j = 1; j <= idx; j++){//completed
			if(t[j]) ans[t[j]]++;
		}
	}
	for(int i = 1; i <= m; i++){
		cout << ans[i] << ' ';
	}
	return 0;
}