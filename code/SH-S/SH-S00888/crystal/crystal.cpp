/*
Vs 1430 T1
-Wall
NO x1 y1 time next prev
freopen("xxx.in","r",stdin);
freopen("xxx.out","w",stdout);
Duo Ce Yao Qing Kong
RP+=INF 
*/
#include <bits/stdc++.h>
using namespace std;
int n;
long long m;
long long a[500020];
long long b[500025];
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin >> n >> m;
	
	for (int i=1; i<=n; i++){
		cin >> a[i];
	}
	sort(a+1,a+n+1);
	long long ans=0;
	for (int i=1; i<=n; i++) b[i]=b[i-1]+a[i];
	for (long long i=1; i<=n; i++){
		// Attribute to Ith 
		long long reqsum=(i-1)*a[i];
		if (reqsum-b[i-1]<=m){
			ans=i;
		}
	}
	cout << ans ;
	return 0;
}
/*
5 8
-3 -1 2 2 7
*/ 
