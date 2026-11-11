#include<bits/stdc++.h>
using namespace std;
int c,n,m,d,q;
//struct node{
//	int num,t;
//	int flag = 0;
//};
//vector<node> k[50010];
//vector<int> r[50010];
int k[50010];
int w[50010];int kk;int a,t;
//priority_queue<long long> qp;
int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	cin>>c>>n>>m>>d>>q;
	for(int i = 1;i<=m;i++){
		cin>>w[i];
	}
	for(int i = 1;i<=n;i++){
		cin>>kk;
		for(int j = 1;j<=kk*2;j++){
			cin>>a>>t;
			k[a]+=t;
		}
	}
	while(q--){
		int ans = 0;
		int x,y;
		cin>>x>>y;
		ans+=w[x]+w[y];
//		cout<<x<<" ";
		ans+=k[x]+k[y];
		cout<<ans<<endl;
	}
	return 0;
} 
