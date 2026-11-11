#include <bits/stdc++.h>

using namespace std;
const int N = 5e5+10;
int n,m;
int a[N], d[N],dl, ans[N];
bool sign = true;

void calc(){
	for (int i = 1;i <= n;i++){
		for (int j = i;j <= n;j++){
			for (int k = 1;k <= dl;k++)	{
				if (d[k] == a[j]) dl = k-1;
			}
			dl++;
			d[dl] = a[j];
		}
		for (int j = 1;j <= dl;j++){
			ans[d[j]]++;
			d[j] = 0;
		}
		dl = 0;
	}
}

void calc_A(){
	for (int i = 1;i <= n;i++){
		for (int j = i;j <= n;j++){
			if (a[j] != a[j+1]) ans[a[j]]++;
		}
	}
}
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);cout.tie(0);
	
	cin >> n >> m;
	
	for (int i = 1;i <= n;i++) {
		cin >> a[i];
		if (a[i] < a[i-1]) sign = false;
	}
	
	if (sign) calc_A();
	else calc();
	for (int i = 1;i <= m;i++) cout << ans[i] << " ";
	return 0;
}

