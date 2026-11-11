#include<bits/stdc++.h>
using namespace std;
#define endl '\n'
const int N = 5e5 + 5;
int n,m,a[N],maxx,minn = 1e9;
int xr(int xq,int yp) {
	int qp = 0;
	for(int i = xq; i <= yp ; i ++ )qp += abs(a[yp] - a[i]);
	return qp;
}
int main() {
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
	cin >> n >> m;
	for(int i = 1; i <= n ; i ++ )cin >> a[i];
	sort(a + 1,a  + n + 1);
	for(int i = 1; i <= n ; i ++ ) {
		int mid = 0,res = 0,l = 0,r = i;
		while(l + 1 <= r) {
			int mid = (l + r) / 2;
			int xqp = xr(mid,i);
			if(xqp >= m ){
				l = mid + 1;
				minn = min(minn,l);
			}else{
				 if(xqp < m ){
				 	res = max(res,r - minn);
				 }
				r = mid - 1;
			}
		}
		maxx = max(maxx,res);
	}
	cout << maxx;
	return 0;
}

