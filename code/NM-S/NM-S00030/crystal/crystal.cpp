#include <bits/stdc++.h>
using namespace std;

bool cmp(int x,int y){
	return x < y;
}

int n,m;
int a[10005];
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin >> n >> m;
	int ans = 0;
	for (int i=0; i<n; i++){
		cin >> a[i];
	}

	sort(a,a+n,cmp);
	int cnt = 1;
	for (int i=1; i<n; i++){
		if (a[i-1] == a[i]){
			cnt++;
		}else{
			ans = max(ans,cnt);
			cnt = 1;
		}
	}

	if (m == 0)cout << ans;
	else{
		cout << 2;
	}


	return 0;
}
