#include <bits/stdc++.h>
using namespace std;
const long long maxn = 5*1e6;
long long n,m,ans,sum;
bool yong;
long long a[maxn],d[maxn];
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cin >> n >> m;
	for(int i=1;i<=n;i++){
		cin >> a[i];
	}
	sort(a+1,a+n+1);
	d[1] = 0;
	if(a[1]==a[n]){
		cout << n;
		return 0;
	}
	yong = false;
	for(int i=2;i<=n;i++){
		d[i] = d[i-1] + (a[i]-a[i-1])*(i-1);
		if((d[i]>m)&&(yong == false)){
			ans = i-1;
			yong = true;
		}
	}
	if(d[n]<=m) ans = n;
	cout << ans;
	
	return 0;
}
