//14:54 Ahahahahah I'm so happy! I AC T1 in 30 minutes!
//		Let's look at T2...
//14:58 呃呃呃这是图论吗？
//		本题题面好似一团浆糊，人类食用后会出现呕吐以及腹泻的症状，并且你的呕吐物以及排泄物会使小 R 的地铁堵塞，使小 R 无法完成出行
//		额我在写什么
//		但是给了测试点编号是个好题目 
//15:06 我才想起来去年 T2 也是图论 
//15:16 我都不知道该怎么存这张图了 
//15:24 505*5e5 的数组都不让开，我该怎么存图 
//15:42 给我逼急了，快 50min 了输入都没写完 
//16:02 写了一团奇妙的东西 
//16:12 小样例居然过了？
//		不过我这一团比题面还浆糊的代码复杂度也就只能过 #1-3
//		那你的意思就是我肝了一个多小时只有 12pts 呗？ 
//16:17 不对我样例 3 怎么还有 WA 的
//		不管了这题就 [0,24]pts，去看一眼 T3 
#include<bits/stdc++.h>
using namespace std;
#define int long long
int c;
int n,m,d,q;
int w[500005];
int a[205][405];
int t[205][405];
int x,y;
int dfs(int subid,int subx,int res){
	if(a[subid][subx]==y)
		return res+t[subid][subx];
	int as=LLONG_MAX/2;
	for(int i=1;i<=n;i++){
		if(i==subid)continue;
		for(int j=1;j<=m;j++){
			if(a[i][j]==a[subid][subx]){
				int ns=a[i][j+1];
				if(ns==0)continue;
				as=min(as,dfs(i,j+1,res+t[subid][subx]+t[i][j]));
			}
		}
	}
	int ns=a[subid][subx+1];
	if(ns!=0)as=min(as,dfs(subid,subx+1,res));
	return as;
}
signed main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	cin>>c;
	cin>>n>>m>>d>>q;
	for(int i=1;i<=m;i++)cin>>w[i];
//	if(c<=8){
		for(int i=1;i<=n;i++){
			int k;
			cin>>k;
			for(int j=1;j<=k;j++)
				cin>>a[i][j]>>t[i][j];
		}
		while(q--){
			cin>>x>>y;
			int res=w[x]+w[y];
			int r=LLONG_MAX/2;
			for(int i=1;i<=n;i++){
				for(int j=1;j<=m;j++){
					if(a[i][j]==x){
						r=min(r,dfs(i,j,t[i][j]));
					}
				}
			}
			res+=r;
//			cerr<<"ans=";
			cout<<res<<'\n';
		}
//	}
	return 0;
} 
/*
0 2 5 20 2
4 1 9 2 5
3 1 5 2 7 4 6
3 2 3 3 4 5 7
1 3
1 2

32
17
*/
/*
0 3 7 20 2
8 3 6 1 7 2 9
3 1 4 2 5 5 100
3 2 6 3 1 7 2
4 3 2 5 100 4 6 6 7
1 6
2 3

35
16
*/
//[0,24]pts 
