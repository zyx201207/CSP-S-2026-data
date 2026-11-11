#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll N=5e5+10;
ll c,n,m,d,q;//样例编号，n条线路，m个站点，最多经过d个站点，有q个出行计划 
ll a[N];//从每个地铁站站口到达站厅的时间
ll su,zhan,shi;
ll f,t; 
int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin>>c>>n>>m>>d>>q;
	for(int i=1;i<=m;i++){
		cin>>a[i];
	}
	for(int i=1;i<=n;i++){
	    cin>>su;
		for(int j=1;i<=su;j++){
			cin>>zhan>>shi;
		}
	}
	for(int i=1;i<=q;i++){
		cin>>f>>t;//起始点，终止点
		
	}
	return 0;
} 
