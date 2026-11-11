#include <bits/stdc++.h>
using namespace std;
long long a[200005];
int main(){
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	long long n, m;
	cin >> n >> m;
	for (int i=1; i<=n; i++){
		cin >> a[i];
	}
	long long ma=-2e9,x,y;
	for (int i=1; i<=n; i++){
		for (int j=i+1; j<=n; j++){
			if ((a[i]&a[j])>ma){
				ma=(a[i]&a[j]);
				x=i;
				y=j;
			}
		}
	}
	a[x]=-1, a[y]=-1;
	for (int k=2; k<m; k++){
		long long q=ma, maxn=-2e9;
		for (int i=1; i<=n; i++){
			if ((q&a[i])>maxn&&a[i]!=-1){
				maxn=(q&a[i]);
				x=i;
			}
		}
		ma=maxn;
		a[x]=-1;
	}
	cout << ma;
	return 0;
}
