#include<bits/stdc++.h>
using namespace std;
int n,m,ans;
int a[500005],b[500005],c[500005],d[500005],e[500005];
bool flag = false;
int qc(int x){
	for(int i = 1;i <= x;i++){
		if(m >= e[x] - ((i - 1) * a[x] - b[i - 1])){
			return i;
		}
	}
	return 0;
}
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin >> n >> m;
	for(int i = 1;i <= n;i ++){
		cin >> a[i];
	}
	sort(a + 1,a + n + 1);
	for(int i = 1;i <= n;i++){
		b[i] = b[i - 1] + a[i];
		e[i] = i * a[i] - b[i];
	}
	for(int i = 1;i <= n;i++){
		int g = qc(i);
		if(g != 0){
			flag = true;
			for(int j = i;j >= 1;j--){
				if(m >= a[i] - a[j]){
					m -= a[i] - a[j];
					c[i] ++;
				}
			}
		}
	}
	if(flag){
		for(int i = 1;i <= n;i ++){
			ans = max(ans,c[i]);
		}
		cout << ans + 1;
	}
	else{
		for(int i = 1;i <= n;i++){
			d[a[i]] ++;
		}
		sort(d + 1,d + n + 1);
		cout << d[n];
	}
	return 0;
}
