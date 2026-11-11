#include<bits/stdc++.h>
using namespace std;
#define int long long
#define PID "hub"
#define FIN freopen(PID".in","r",stdin)
#define FOU freopen(PID".out","w",stdout)
int n,m;
int a[1005];
signed main(){
	FIN;FOU;
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	cin >> n >> m;
	if(n<m){
		int a,b;
		cin>>a>>b;
		if(abs(a+b)==7){
			cout <<	(n+m)/2 << endl;
			cout << abs(n+m) << endl;
		}else{
			cout <<	(n+m)%2 << endl;
			cout << abs(n+m)/2 << endl;	
		}	
	}
	return 0;
}
