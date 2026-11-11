#include <bits/stdc++.h>
#define int long long
using namespace std;
int w[500005],k[505],a[505][20005],t[505][20005],st[505][505];
signed main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	int CCCCC,n,m,D,q;
	cin>>CCCCC>>n>>m>>D>>q;
	for(int i=1;i<=m;i++)cin>>w[i];
	memset(st,0x3f,sizeof(st));
	for(int i=1;i<=n;i++){
		cin>>k[i];
		for(int j=1;j<=k[i];j++)cin>>a[i][j]>>t[i][j];
		for(int j=1;j<=k[i];j++){
			for(int l=j+1;l<=k[i];l++){
				st[a[i][j]][a[i][l]]=st[a[i][l]][a[i][j]]=t[i][j]+t[i][l]; 
			}
		}
	}
	for(int i=1;i<=m;i++){
		for(int j=1;j<=m;j++){
			if(i==j)continue;
			for(int tk=1;tk<=m;tk++){
				if(i==tk||j==tk)continue;
				st[i][j]=min(st[i][j],st[i][tk]+st[tk][j]);
			}
		}
	}
	while(q--){
		int s,t;
		cin>>s>>t;
		cout<<w[s]+w[t]+st[s][t]<<"\n";
	}
	return 0;
}
/*
我要上迷惑大选。
因为如果我没上，那么就会有人拿混凝土拌36号意大利面
导致我的CSP-S变成奶龙吞噬世界
然后大狗就不叫
于是挖掘机变异发出炫酷无敌七彩闪光吊炸天的尖锐爆鸣。
破坏鼻腔黏膜，导致眼睛不停流血十分惊悚
让史蒂夫流口水觉得卡时间段疯狂拉水电费可以活动100分。
于是案例库电焊工就会发狂开始使用电击器电击电击器，并严肃思考
电击器电击电击器，电击器会不会被电击电坏 
*/
