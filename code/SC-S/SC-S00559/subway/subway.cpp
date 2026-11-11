#include<bits/stdc++.h>
#define int long long
using namespace std;
int n,m,c,d,q;
int w[500005];
struct node{
	int id,w;
};
int f[505][505];
vector<node>hh[500005];
int read(){
	int x=0,f=1;
	char c=getchar();
	while(c<'0'||c>'9'){
		if(c=='-')f=-1;
		c=getchar();
	}
	while(c>='0'&&c<='9'){
		x=x*10+c-'0';
		c=getchar();
	}
	return f*x;
}
signed main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	c=read(),n=read(),m=read(),d=read(),q=read();
	for(int i=1;i<=m;i++){
		w[i]=read();
	}
	/*
	发现了n好像特别小
	说明中间一个点最多换乘列车500次？？
	询问特别多，车站也多
	发现可以设计DP
	f[i][j]表示从第i条线到第j条线的最快步行时长
	直接枚举 d*d*q;
	还有2:33 切了
	快读好像打错了
	好像有点超时
	开始卡常吧,卡个20分钟换题
	时间复杂度是d*d*m？？？
	2*10^8
	懒得写了。。。。
	别挂别挂别挂别挂别挂别挂别挂别挂别挂别挂别挂别挂别挂别挂别挂别挂别挂别挂别挂别挂别挂别挂别挂别挂别挂别挂别挂别挂别挂别挂别挂别挂别挂别挂别挂别挂别挂别挂别挂别挂别挂别挂别挂别挂别挂别挂别挂别挂别挂别挂别挂别挂别挂别挂别挂别挂别挂别挂别挂别挂别挂别挂别挂别挂别挂别挂别挂别挂别挂别挂别挂别挂别挂
	*/
	for(int i=1;i<=n;i++){
		int siz;
		siz=read();
		for(int j=1;j<=siz;j++){
			int a,vl;
			a=read(),vl=read();
			hh[a].push_back({i,vl});
		}
	}
	for(int i=1;i<=n;i++){
		for(int j=1;j<=n;j++){
			f[i][j]=1e18;
		}
		f[i][i]=0;
	}
	for(int i=1;i<=m;i++){
		for(node v1:hh[i]){
			for(node v2:hh[i]){
				if(v1.id==v2.id)continue;
				f[v1.id][v2.id]=min(f[v1.id][v2.id],v1.w+v2.w);
				f[v2.id][v1.id]=min(f[v2.id][v1.id],v1.w+v2.w);
			}
		}//优化成每个的最小值
	}
	for(int k=1;k<=n;k++){
		for(int i=1;i<=n;i++){
			for(int j=1;j<=n;j++){
				f[i][j]=min(f[i][j],f[i][k]+f[k][j]);
			}
		}
	}
//	for(int i=1;i<=n;i++){
//		for(int j=1;j<=n;j++){
//			cout<<f[i][j]<<" ";
//		}
//		cout<<endl;
//	}
	while(q--){
		int x,y;
		x=read(),y=read();
		int sm=w[x]+w[y];
		int ans=1e18;
		for(node v1:hh[x]){
			for(node v2:hh[y]){
				ans=min(ans,f[v1.id][v2.id]+v1.w+v2.w);
			}
		}
		cout<<ans+sm<<'\n';
	}
	return 0;
}
/*
0 2 5 20 2
4 1 9 2 5
3 1 5 2 7 4 6
3 2 3 3 4 5 7
*/