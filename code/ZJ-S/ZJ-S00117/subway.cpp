#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N=5e5+10;
int c,n,m,d,q;
int w[N];
vector<pair<int,int>>a,t;
vector<int>v[N];
int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	cin>>c>>n>>m>>d>>q;
	for(int i=1;i<=m;i++){
		cin>>w[i];
	}
	for(int i=1;i<=n;i++){
		int k;
		cin>>k;
		for(int j=1;j<=k;j++){
			int x;
			cin>>x;
			int t;
			cin>>t;
			a.push_back({i,x});
		}
	}
	for(int i=1;i<=n;i++){
		cout<<"   |  |   "<<endl;
	}
	for(int i=1;i<=2;i++){
		cout<<" 00000000"<<endl;
	}
	return 0;
}
