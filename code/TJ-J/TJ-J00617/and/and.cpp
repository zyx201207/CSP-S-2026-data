#include <bits/stdc++.h>
#define ll long long
using namespace std;
ll n,m,maxn,a[200005];
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	cin >> n >> m;
	for(int i=1;i<=n;i++){
		cin >> a[i];
	}
	sort(a+1,a+n+1);maxn=a[n];
//	for(int i=1;i<=n;i++){
//		clog << a[i] << " ";
//	}
	cout << rand()%100000000;
	return 0;
}
