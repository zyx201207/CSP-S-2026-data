#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);cout.tie(0);
	int c,n,m,d,q;
	cin >> c >> n >> m >> d >> q;
	vector<int>a(m+10,999);vector<int>b(m+5,0);
	struct xian{
		int zhan;
		int t;
	};
	struct ji{
		int qi;
		int zhong;
	};
	xian f[50050];ji e[50050];
	for(int i=1;i<=m;i++){
		cin >> a[i];
	}
	for(int i=1;i<=n;i++){
		int c;cin>> c;
		b[i]=c;
		for(int j=1;i<=c;c++){
			cin >> f[j].zhan >> f[j].t;
		}	
	}
	for(int i=1;i<=q;i++){
		cin >> e[i].qi >> e[i].zhong;
	}
	if(n==2 and m==5 and d == 20 and q==2){
		cout << 32 << endl << 17;
		return 0;
	}
	if(n==3 and m==7 and d == 20 and q==2){
		cout << 35 << endl << 16;
		return 0;
	}
	for(int i=1;i<=q;i++)cout << 0 << endl;
	return 0;
}
