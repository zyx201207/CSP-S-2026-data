#include<iostream>
#include<vector>
#include<algorithm>
#include<queue>
using namespace std;
const int N=520;
struct p{
	int a,t;
};
long long c,n,m,d,q,dp[N][N];
int main(){
	//freopen("subway.in","r",stdin);
	//freopen("subway.out","w",stdout);
	ios::sync_with_stdio(0);cin.tie(0);
	cin>>c>>n>>m>>d>>q;
	int M=n+m;
	vector<int> w(m+1);
	for(int i=1;i<=m;i++) cin>>w[i];
	for(int i=1;i<=M;i++){for(int j=1;j<=M;j++){dp[i][j]=10e9;}}
	for(int i=1;i<=n;i++){
		int k;cin>>k;
		for(int j=1;j<=k;j++){
			int a,t;
			cin>>a>>t;
			dp[a][m+j]=t;
			dp[m+j][a]=t;
		}
	}
	for(int i=1;i<=M;i++){
		for(int j=1;j<=M;j++){
			for(int k=1;k<=M;k++){
				dp[i][k]=min(dp[i][j]+dp[j][k],dp[i][k]);
				dp[k][i]=dp[i][k];
			}
		}
	}
	int c1,c2;
	while(q--){
		cin>>c1>>c2;
		cout<<dp[c1][c2]+w[c1]+w[c2]<<endl;
	}
	return 0;
}
/*
#include<iostream>
#include<vector>
#include<algorithm>
#include<queue>
using namespace std;
int c,n,m,d,q;
const int MAXN=1e9;
struct p{
	int t,a,p;
};
vector<p> tre[30];
vector<p> ttre;
vector<p> btre[30];
bool cmp(p x,p y){
	return x.t>y.t;
}
int main(){
	//freopen("subway.in","r",stdin);
	//freopen("subway.out","w",stdout);
	ios::sync_with_stdio(0);cin.tie(0);
	cin>>c>>n>>m>>d>>q;
	vector<int>w(m+1);
	for(int i=1;i<=m;i++) cin>>w[i];
	for(int i=1;i<=n;i++){
		int k;cin>>k;
		for(int j=1;j<=k;j++){
			int a,t;cin>>a>>t;
			p now;now.a=a;now.t=t;now.p=i;
			tre[i].push_back(now);
			ttre.push_back(now);
			//cout<<'('<<tre[i][j-1].a<<' '<<tre[i][j-1].t<<')'<<endl;
		}
		sort(tre[i].begin(),tre[i].end(),cmp);
	}
	sort(ttre.begin(),ttre.end(),cmp);
	for(int i=0;i<ttre.size();i++){
		cout<<'('<<ttre[i].a<<' '<<ttre[i].t<<' '<<ttre[i].p<<')'<<endl;
	}cout<<endl;
	vector<bool>vis(m+1),vis2(n+1);int hvis=m-1;
	for(int i=0;i<=m;i++) vis[i]=0;vis[1]=1;
	for(int i=0;i<=n;i++) vis2[i]=0;
	while(!ttre.empty()){
		
	}
	for(int i=1;i<=n;i++){
		for(int j=0;j<tre[i].size();j++){
			cout<<'('<<btre[i][j].a<<' '<<btre[i][j].t<<')'<<endl;
		}
		cout<<endl;
	}
	return 0;
}
*/