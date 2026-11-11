#include<bits/stdc++.h>
using namespace std;
const int N=505;
const int M=5e5+5;
long long op,n,m,d,q;
long long w[M];
bool p[N];
bool so=0;
vector<long long>sta;
struct line{
	long long li,tim;
};
struct node{
	long long to,ti;
};
//vector<line>st;
vector<node>a[M];


void solve(){
	long long fi;
	long long en;
	cin>>fi>>en;
	queue<long long>q;
	queue<long long>val;
	for(int i=1;i<=m;i++){
		p[i]=1;
	}
	q.push(fi);
	val.push(0);
	while(!q.empty()){
		long long x=q.front();
		long long y=val.front();
		q.pop();
		val.pop();
		p[x]=0;
//		cout<<x<<'\n';
//		for(int i=1;i<=m;i++){
//			cout<<p[i]<<' ';
//		}
//		cout<<'\n';
		//cout<<x<<' '<<y<<'\n';
		if(x==en){
			cout<<y+w[fi]+w[en]<<'\n';
			return;
		}
		for(int i=0;i<a[x].size();i++){	
			//cout<<a[x][i].to<<' ';
			if(p[a[x][i].to]){
				p[a[x][i].to]=0;
				q.push(a[x][i].to);
				val.push(y+a[x][i].ti);
			}
		}
		//cout<<'\n';
	}
//	so=0;
//	ans=dfs(x,y,0);
	//cout<<ans+w[x]+w[y]<<'\n';
}

int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	cin>>op>>n>>m>>d>>q;
	for(int i=1;i<=m;i++){
		cin>>w[i];
	}
	for(int i=1;i<=n;i++){
		long long k;
		cin>>k;
		vector<line>st;
		for(int j=1;j<=k;j++){
			long long x,y;
			cin>>x>>y;
			st.push_back({x,y});
		}
		for(int j=0;j<k;j++){
			for(int z=j+1;z<k;z++){
				a[st[j].li].push_back({st[z].li,st[j].tim+st[z].tim});
				a[st[z].li].push_back({st[j].li,st[j].tim+st[z].tim});
			}
		}
	}
//	for(int i=1;i<=m;i++){
//		for(int j=0;j<a[i].size();j++){
//			cout<<a[i][j].to<<' '<<a[i][j].ti<<'\n';
//		}
//		cout<<'\n';
//	}
//	cout<<'\n';
	while(q--){
		solve();
	}
	return 0;
}
