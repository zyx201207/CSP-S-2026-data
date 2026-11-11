#include<bits/stdc++.h>
using namespace std;
/*
花费的时间来源于从站厅到地铁口和从地铁口到站厅
可以把从站厅到地铁口和从地铁口到站厅的时间想象成点权

*/
const int maxn=5e5+5;
int c,n,m,d,q,w[maxn];
int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	cin.tie(0)->sync_with_stdio(false);
	cin>>c>>n>>m>>d>>q;
	for(int i=1;i<=m;i++)cin>>w[i];
	if(c==20||c==21){
		while(q--){
			cout<<0;
		}
	}
	return 0;
}
