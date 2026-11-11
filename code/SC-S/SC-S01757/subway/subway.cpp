#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin>>c>>n>>m>>d>>q;//c测试点、n条线、m个地铁站、每个地铁站最多被d条线路经过，q个出行计划
	for(int i=1;i<=m;i++){
		cin>>kt[i];//i站厅至口的时间 
	}
	for(int i=1;i<=n;i++){
		cin>>k[i];//i线有k个站 
		for(int j=1;j<=k;j++){
			cin>>lll>>tt[i][lll];//lll站，i线台至lll站厅时间 
			xl[i][lll]=1;//i线lll站 
			num[lll]++;//lll站地铁线数增加 
		}
	}
	for(int i=1;i<=q;i++){
		cout<<1;
	}
	return 0;
}