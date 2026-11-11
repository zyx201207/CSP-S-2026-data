#include<bits/stdc++.h>
#define N 500015
using namespace std;
void hey() {
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
}
int n,m,d,q;
	int c;
int w[N];
vector<pair<int,int> > a[505];
//        place cost
vector<int> line[N];
//某节点可以去那条线
struct str{
	int sta; //这个站换
	int point;//换乘线路处于当前 线的相对位置
	int go;//换乘线路去对面线的位置
	int cost;
	int toline;//去那个线
};
vector<int> cha;
//可以换成的点
vector<str> change[505];
//记录换乘线路的方式
struct node{//记录bfs中当前状态
	int nline;//在哪条线
	long long spend;//花了多少
	int place;//当前 线的相对位置
};
int econ[505];//终点在线的相对位置
int find(int li,int x) {//在第i号线找x点
	for(int i=0;i<a[li].size();i++) {
		if(a[li][i].first==x) return i;
	}
	return -1;
}
void init() {//输入，换线等预处理
	
	scanf("%d%d%d%d%d",&c,&n,&m,&d,&q);
	for(int i=1;i<=m;i++) {
		scanf("%d",&w[i]);
	}
	for(int i=1;i<=n;i++) {
		int t;
		scanf("%d",&t);
		for(int j=1;j<=t;j++) {
			int x,y;
			scanf("%d%d",&x,&y);
			a[i].push_back({x,y});
			line[x].push_back(i);
			if(line[x].size()==2) cha.push_back(x);
		}
	}
	for(int i=0;i<cha.size();i++) {
		for(int j=0;j<line[cha[i]].size();j++) {
			for(int k=0;k<line[cha[i]].size();k++) {
				if(j==k) continue;
				int x=find(line[cha[i]][j],cha[i]),y=find(line[cha[i]][k],cha[i]);
//				cout<<x<<' '<<y<<'\n';
				int p=a[line[cha[i]][j]][x].second+a[line[cha[i]][k]][y].second;
				change[line[cha[i]][j]].push_back({cha[i],x,y,p,line[cha[i]][k]});
				change[line[cha[i]][k]].push_back({cha[i],y,x,p,line[cha[i]][j]});
			}
		}
	}
}
int check(node x) {
	if(econ[x.nline]!=-1) {
		return 1;
	}
	return 0;
}
int hi[505];
long long bfs(int s,int e) {
	memset(hi,0,sizeof(hi));
	long long ans=214748364;
	queue<node> Q;
//			cout<<"?";
	for(int i=0;i<line[s].size();i++) {
//			cout<<"?";
		int x=find(line[s][i],s);
		Q.push({line[s][i],a[line[s][i]][x].second,x});
		hi[line[s][i]]=1;
//		cout<<a[line[s][i]][x].second;
	}
//	cout<<Q.size();
	while(Q.size()) {
//			cout<<"?";
		node u=Q.front();
		Q.pop();
		if(u.spend>=ans) continue;
		if(check(u)) {
			ans=min(ans,u.spend+a[u.nline][econ[u.nline]].second);
			continue;
		}
		for(int i=0;i<change[u.nline].size();i++) {
//			cout<<"?";
//			cout<<u.nline<<' '<<change[u.nline][i].toline<<' '<<change[u.nline][i].point<<' '<<change[u.nline][i].go<<'\n';
//			cout<<change[u.nline][i].cost;
			if(change[u.nline][i].point!=u.place) {
				Q.push({change[u.nline][i].toline,u.spend+change[u.nline][i].cost,change[u.nline][i].go});
			}
		}
	}
	return ans;
}
signed main() {
	hey();
	init();
	while(q--) {
		int B,E;
		scanf("%d%d",&B,&E);
		long long ans=0;
		if(B==E) {
			printf("0\n");
			continue;
		}
		ans+=w[B]+w[E];
//		cout<<ans<<'\n';
		for(int i=1;i<=n;i++) {
			econ[i]=find(i,E);
		}
		ans+=bfs(B,E);
		printf("%lld\n",ans);
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}
