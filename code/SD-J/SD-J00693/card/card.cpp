#include <bits/stdc++.h>
using namespace std;

const int N = 5e5 + 1000;
int n,m;
int f[N],a[N];
bool b[N];
bool c[N];
int sum[N];
int ans[N];

int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	cin.tie(0)->sync_with_stdio(0);
	cin >> n >> m;
	for(int i = 1;i <= n;i++)
		cin >> a[i];
	for(int i = n;i;i--)
		if(c[a[i]] == 0){
			b[i] = 1;
			c[a[i]] = 1;
		}
	for(int i = 1;i <= n;i++){
		if(b[i-1] == 1)
			f[i] += f[i-1];
		f[i]++;
		if(b[i] == 1) 
			f[i] += sum[a[i]];
		sum[a[i]] += f[i];
	}
	
	
	for(int i = 1;i <= n;i++)
		if(b[i])
			ans[a[i]] = f[i];
	for(int i = 1;i <= m;i++){
		cout << ans[i];
		if(i < m) cout << ' ';
	}
	return 0;
}

