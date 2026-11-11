#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N=6e6+7;
struct good{
	int x,jia;
};
vector < good > rode[N];
int chujia[N];
int c,n,m,d,q;
struct god{
	int x,jia;
};
bool operator < (god x,god y){
	return x.jia > y.jia ;
}
priority_queue < god > pai;
bool zuo[N];
int ans[N];
int dist(int x,int y){
	while(pai.size())pai.pop();
	for(int i=1;i<=n+m;i++){
		zuo[i]=0;
		ans[i]=N;
	}
	god chu;
	chu.x =x;
	chu.jia =0;
	pai.push(chu);
	ans[x]=0;
	while(pai.size()){
		god xx=pai.top();
		pai.pop();
		if(zuo[xx.x ])continue;
		zuo[xx.x ]=1;
		for(int i=1;i<rode[xx.x].size();i++){
			int yy=rode[xx.x ][i].x,jia=rode[xx.x ][i].jia;
			if(ans[yy]>jia+xx.jia ){
				god yyy;
				yyy.x =yy;
				yyy.jia =jia+xx.jia ;
				ans[yy]=yyy.jia ;
				pai.push(yyy);
			}
		}
	}
	return ans[y];
}
signed main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin>>c>>n>>m>>d>>q;
	for(int i=1;i<=n+m;i++){
		good x;
		x.x=x.jia=-1;
		rode[i].push_back(x);
	}
	for(int i=1;i<=m;i++){
		cin>>chujia[i];
	}
	for(int i=1;i<=n;i++){
		int k;
		cin>>k;
		for(int j=1;j<=k;j++){
			int y,time;
			cin>>y>>time;
			good t1,t2;
			t1.jia =t2.jia =time;
			t1.x =y;
			t2.x =i+m;
			rode[i+m].push_back(t1);
			rode[y].push_back(t2);
		}
	}
	for(int i=1;i<=q;i++){
		int x,y;
		cin>>x>>y;
		cout<<dist(x,y)+chujia[x]+chujia[y]<<"\n";
	}
}
/*
0 2 5 20 2
4 1 9 2 5
3 1 5 2 7 4 6
3 2 3 3 4 5 7
1 3
1 2



*/
