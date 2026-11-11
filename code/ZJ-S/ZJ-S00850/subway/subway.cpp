#include<bits/stdc++.h>
#define int long long
#define endl '\n'
using namespace std;
const int N=5e5+5;
int c,n,m,d,q;
int w[N];
map<int,int>dp[N];
struct node{
	int t,id;
};
vector<node>ve[N];
map<int,bool>vis[N];
vector<int>nex[N];
int minn[505];
signed main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	cin>>c>>n>>m>>d>>q;
	for(int i=1;i<=m;i++){
		cin>>w[i];
	}
	for(int i=1;i<=n;i++){
		int k;
		cin>>k;
//		cout<<k<<endl;
		for(int j=1;j<=k;j++){
			int c,b;
			cin>>c>>b;
			ve[c].push_back({b,i});
			vis[c][i]=1;
		}
	}
//	cout<<1;
//	for(int i=1;i<=m;i++){
//		cout<<i<<endl;
//		for(int j=0;j<ve[i].size();j++){
//			cout<<ve[i][j].t<<" "<<ve[i][j].id<<endl;
//		}
//	}
}
//0 2 5 20 2
//4 1 9 2 5
//3 1 5 2 7 4 6
//3 2 3 3 4 5 7
//1 3
//1 2
//QwQ