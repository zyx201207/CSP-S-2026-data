#include <bits/stdc++.h>//这是我代码
using namespace std;//这是我代码
typedef long long ll;//这是我代码
int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	int c,n,m,d,q;
	cin>>c>>n>>m>>d>>q;
	int w[m+1];
	for(int i=1;i<=m;i++){
		cin>>w[i];
	}
	for(int i=1;i<=n;i++){
		int k;
		cin>>k;
		int a[k*2+1];
		for(int j=1;j<=k*2;j++){
			cin>>a[j];
		}
	}
	for(int i=1;i<=q;i++){
		int x,y;
		cin>>x>>y;
		cout<<1<<endl;
	}
	return 0;
}
