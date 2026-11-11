#include<bits/stdc++.h> 
#define int long long
using namespace std;
int c, n, m, d, q;
int w[1005];
int e[505][405];
int l[405][405];
signed main(){
	freopen("subway.in", "r", stdin);
	freopen("subway.out", "w", stdout);
	cin >> c >> n >> m >> d >> q;
	for(int i=1;i<=m;i++) cin >> w[i];
	for(int i=1;i<=n;i++){
		int opm;
		cin >> opm;
		for(int i=1;i<=opm;i++){
			int a, b;
			cin >> a >> b;
			e[i][a]=b;
		} 
	}
//	for(int i=0;i<405;i++) for(int j=0;j<405;j++) if(i!=j) l[i][j]=1000000000000000000;
//	for(int k=1;k<=m;k++){
//		for(int i=1;i<=m;i++){
//			for(int j=1;j<=m;j++){
//				
//			}
//		}
//	}
	for(int i=1;i<=q;i++){
		int a, b;
		cin >> a >> b;
		cout << w[a]+w[b] << "\n";
	}
	return 0;
}
















//被逼疯了已经，颓了 
//旁边的给了巨大压力
//还有画画高手 
/*想上行为大赏 
  “坏人的血才是黑色的，我们总是万紫千红。一方水土养一方人精，浪费粮食还装作清醒”——《花桥》
  “你在为着什么而流着血？”——《鬼》
  “你说不想在这里，我也不想在这里。但天黑得太快想走也会来不及。但是我爱你，可惜关系变成没关系”——《但》
  “分开是难过不能说~”——《其实》 
  “陪你去看流星雨落在这地球上，你的泪落在我的肩上。”——《流星雨》 
  “他从天上掉人间”——《择日飞仙》
  “ 
*/
/*
我方部队夺取了一个战区 
*/ 
/*
kards 
*/
/*
cnmd  ��￡ 
*/
/*
  what do we do with a drunken soider?
  what do we do with a drunken soider?
  what do we do with a drunken soider?
  () up in the morning 
  hey hey the () raises!
  hey hey the () raises!
  hey hey the () raises!
  () up in the morning 
*/  
