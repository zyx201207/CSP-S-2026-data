#include<bits/stdc++.h>
#define ll long long
#define ull unsigned long long
using namespace std;
const int M=5e5+5,N=505;
int c,n,m,d,q,fA,fB,fB_T;
int w[M],k[N];
vector<int>a[N],t[N];
int folyd[305][305];
void solve1(){
	for(int i=1;i<=n;i++){
//k[i]表示第 i 条线路经过的地铁站数
//a[i][]表示第 i 条线路经过的第 j 个地铁站
//t[i][]从该地铁站的站厅走到第 i 条线路的站台需要的时间j
		for(int s1:a[i]){
			t[i][]
		}
	}
}
void solve2(){
	for(int i=1;i<=n;i++){
//k[i]表示第 i 条线路经过的地铁站数
//a[i][]表示第 i 条线路经过的第 j 个地铁站
//t[i][]从该地铁站的站厅走到第 i 条线路的站台需要的时间j
		
	}
}
//每条线路至多经过 2 个地铁站
void solve3(){
	for(int i=1;i<=n;i++){
//k[i]表示第 i 条线路经过的地铁站数
//a[i][]表示第 i 条线路经过的第 j 个地铁站
//t[i][]从该地铁站的站厅走到第 i 条线路的站台需要的时间j
		
	}
}
int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin>>c>>n>>m>>d>>q;
	fB=fA=1;
	for(int i=1;i<=m;i++)cin>>w[i];
//表示从每个地铁站的地铁口走到站厅需要的时间
	for(int i=1;i<=n;i++){
		cin>>k[i];
		if(k[i]>2)fA=0;
//表示第 i 条线路经过的地铁站数
		for(int j=1;j<=k[i];j++){
			int s1,s2;
			cin>>s1>>s2;
			a[i].push_back(s1);
//表示第 i 条线路经过的第 s1 个地铁站
			t[i].push_back(s2);
//从该地铁站的站厅走到第 i 条线路的站台需要的时间(s2)
			if(i==1&&j==1)fB_T=s2;
			else{
				if(fB_T!=s2)fB=0;
			}
		}
	}
	if(n<=300)solve1();
	if(fA)solve2();
	if(fB)solve3();
	while(q--){
		int x,y;
		cin>>x>>y;
		//计划的最小总步行时间
	}
	return 0;
}
//1~6 floyd
//看不懂 
