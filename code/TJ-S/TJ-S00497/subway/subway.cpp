#include<bits/stdc++.h>
using namespace std;
int w[500005],num[505];
struct st{
	int wa;
	int t;
}a[505];
int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	int c,n,m,d,q;
	cin>>c>>n>>m>>d>>q;
	for(int i=1;i<=m;i++) cin>>w[i];
	for(int i=1;i=n;i++){
		cin>>num[i];
		for(int j=1;j<=2*num[i];j++){
			cin>>a[j].wa>>a[j].t;
		}
	}
	for(int i=1;i<=q;i++){
		int x,y;
		cin>>x>>y;
	}
	return 0;
}
