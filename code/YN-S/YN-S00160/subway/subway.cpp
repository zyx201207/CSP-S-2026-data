#include<bits/stdc++.h>
using namespace std;
int c,m,n,d,p;
struct{
	int w;
}station[505];
struct{
	vector<int> a;
	vector<int> t;
}subway[505];
int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	cin >> c >> m >> n >> d >> p;
	for(int i = 1;i <= m;i++){
		cin >> station[i].w;
	}
	int k,aa,tt;
	for(int i = 1;i <= n;i++){
		cin >> k;
		for(int j = 1;j <= k;j++){
			cin >> aa >> tt;
			subway[i].a.push_back(aa);
			subway[i].t.push_back(tt);
		}
	}
	int sx,ex;
	for(int i = 1;i <= p;i++){
		cin >> sx >> ex;
	}
	return 0;
}
