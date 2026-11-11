#include<bits/stdc++.h>
using namespace std;
#define int long long
#define PID "crystal"
#define FIN freopen(PID".in","r",stdin)
#define FOU freopen(PID".out","w",stdout)
int n,m;
signed main(){
	FIN;FOU;
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	cin >> n >> m;
	if(n==m){
		cout << abs(n/m*3) << endl;
	}else{
		cout << abs(n-m)+1 << endl;
	}
	return 0;
}
