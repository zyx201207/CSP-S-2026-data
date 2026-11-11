#include<bits/stdc++.h>
#define int long long
#define pii pair<int,int>
#define F first
#define S second
using namespace std;
const int N=5e5+18;
int n,m,a[N],q[N],l,r,ans;
bool chk(int x,int y){
//	cout << x << ' ' << y << '\n';
//	cout << a[1] << ' ' << a[y] << '\n';
//	cout << q[0] <<' '<<q[1]<<' '<<q[2]<<' '<<q[3]<<'\n'; 
	int t=(y-x)*a[y];
	int tt=t-(q[y-1]-q[x-1]);
	//cout << x << ' ' << y << ' ' << t << ' ' << tt << '\n';
	//cout << tt << '\n';
	if(tt<=m) return 1;
	return 0;
}
signed main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
//	ios::sync_with_stdio(0);
//	cin.tie(0);cout.tie(0);
	cin >> n >> m;
	for(int i=1;i<=n;i++){
		cin >> a[i];
	}sort(a+1,a+n+1);
	for(int i=1;i<=n;i++){
		q[i]=q[i-1]+a[i];
	}
//	for(int i=1;i<=n;i++){
//		cout << a[i] << '\n';
//	}
	l=1,r=1;
	for(int i=1;i<=n;i++){
		r=i;
		while(!chk(l,r)&&l<r){
			l++;
		}ans=max(ans,r-l+1ll);
	}cout << ans << '\n';
	return 0;
}
// Oct31==Dec25?
