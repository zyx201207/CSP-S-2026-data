#include<bits/stdc++.h>
using namespace std;
//const int INF=0x7FFFFFFF;
const int N=5E5+10;
#define ll long long
int c,n,m,d,q,k,w,rx,ry;
int stat1,wait1;
struct station{
	int id;
	int Belong;
	int ChuRuZhan;
	int ShangChe[505],cnt;
}a[N];
vector<pair<int,int> >G[N];
bool vis[N];
int ans[N];
void DFS(int SumTime,int SD){
//	cout<<SD<<" ";
	ans[SD]=min(ans[SD],SumTime);
	vis[SD]=1;
	int Len=G[SD].size();
	for(int i=0;i<Len;i++)
		if(!vis[G[SD][i].first]){
			DFS(SumTime+G[SD][i].second,G[SD][i].first);
			vis[i]=0;
		}
}
int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	scanf("%d%d%d%d%d",&c,&n,&m,&d,&q);
	for(int i=1;i<=m;++i){
		scanf("%d",&w);
		a[i].id=i;
		a[i].ChuRuZhan=w;
	}
	for(int i=1;i<=n;++i){
		cin>>k;
		int pre;
		cin>>stat1>>wait1;
		pre=stat1;
		++a[stat1].cnt;
		a[stat1].ShangChe[a[stat1].cnt]=wait1;
		if(a[stat1].cnt<=1){
			G[pre].push_back({stat1,0});
			G[stat1].push_back({pre,0});
		}
		else{
			G[pre].push_back({stat1,a[stat1].ShangChe[a[stat1].cnt-1]+wait1});
			G[stat1].push_back({pre,a[stat1].ShangChe[a[stat1].cnt-1]+wait1});
		}
		for(int j=2;j<=k;++j){
			cin>>stat1>>wait1;
			++a[stat1].cnt;
			a[stat1].ShangChe[a[stat1].cnt]=wait1;
			if(a[stat1].cnt<=1){
				G[pre].push_back({stat1,0});
				G[stat1].push_back({pre,0});
			}
			else{
				G[pre].push_back({stat1,a[stat1].ShangChe[a[stat1].cnt-1]+wait1});
				G[stat1].push_back({pre,a[stat1].ShangChe[a[stat1].cnt-1]+wait1});
			}
			pre=stat1;
		}
	}
//	for(int i=1;i<=m;i++)
//		cout<<a[i].cnt<<" ";
//	cout<<"\n";
	while(q--){
		memset(ans,0x3F,sizeof ans);
		memset(vis,0,sizeof vis);
		cin>>rx>>ry;
//		for(int i=1;i<=m;i++)
//			cout<<ans[i]<<" ";
//		cout<<a[rx].cnt<<"\n";
		for(int i=1;i<=a[rx].cnt;i++)
			DFS(a[rx].ShangChe[i],rx);
		cout<<a[rx].ChuRuZhan<<"+"<<ans[ry]<<"+"<<a[ry].ChuRuZhan<<"=";
		cout<<a[rx].ChuRuZhan+ans[ry]+a[ry].ChuRuZhan<<"\n";
//		for(int i=1;i<=m;i++)
//			cout<<ans[i]<<" ";
//		cout<<"\n";
	}
	return 0;
}
