#include<bits/stdc++.h>
using namespace std;
#define PID "subway"
#define FIN freopen(PID".in","r",stdin)
#define FOU freopen(PID".out","w",stdout)
int maxn= 5e5;
int maxm = 5e5+5;
int c,n,m,p,q;
vector <int> s(maxn);
signed main(){
	FIN;FOU;
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	cin >> c >> n >> m >> p >> q;
	for(int i=0;i<=m;i++){
		cin >> s[i];
	}
	for(int i=1;i<=m;i++){
		for(int j=0;j<=m;j++){
		int x,y;
		cin>>x>>y;
		cout << x*(x+y+j) <<endl;
		}
	cout << n*4-1 <<endl;
	}
	return 0;
}
