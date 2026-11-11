#include<bits/stdc++.h>
using namespace std;
long long c,n,m,d,q,w[500010],ans;
int main(){
	//w地铁站-站厅 n线路数 m站数 d每个地铁站最多被几条线路经过 q出行计划数 
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0),cout.tie(0);
	cin>>c>>n>>m>>d>>q;
	for(int i=1;i<=m;i++){
		cin>>w[i];
		ans+=w[i];
	}
	cout<<ans;
	return 0;
} 
