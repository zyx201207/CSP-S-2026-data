#include<bits/stdc++.h>
#define int long long
using namespace std;
const int maxn = 5e5+10;
int a[maxn];
int ans[maxn];
signed main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	int n,m;cin>> n >> m;
	for(int i = 1;i <= n;i++){
		cin >> a[i];
	}
	for(int i = 1;i <= n;i++){
		int xit = i;
		for(int j = i;j <= n;j++){
			if(a[xit] == a[j])xit = j;
		}
		for(int j = xit;j <= n;j++){
			ans[a[j]]++;
		}
	}
	for(int i = 1;i <= m;i++)cout << ans[i] << ' ';
	return 0;
}
