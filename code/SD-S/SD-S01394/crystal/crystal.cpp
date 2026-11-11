#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N = 500025;
int a[500025],s[500025];
int ans;
signed main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	int n;
	int m;
	cin >> n;
	cin >> m;
	for(int i = 1;i <= n;i ++){
		cin >> a[i];
	}
	sort(a + 1,a + n + 1);
	for(int i = 1;i <= n;i ++){
		s[i] = s[i - 1] + a[i];
	}
	int maxx = 0;
	int maxs,maxa;
	for(int i = 1;i <= n;i ++){
	 	s[i] += m;
	 	if(a[i] == 0){
	 		continue;
		}
		else if(a[i] != 0){
			ans = min(i,s[i] / a[i]);
		}
		maxx = max(maxx,ans);
	}
	cout << maxx;
	return 0;
}

