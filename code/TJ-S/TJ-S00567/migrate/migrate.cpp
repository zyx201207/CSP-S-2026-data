#include<bits/stdc++.h>
using namespace std;
struct node{
	int to,w;
};
vector<node> g[2000005];
int main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	int c,t;
	cin>>c>>t;
	while(t--){
		int n,d;
		cin>>n>>d;
		vector<int> a(n+5);
		for(int i=1;i<=n;i++){
			cin>>a[i];
		}
		for(int i=1;i<n;i++){
			for(int j=i+1;i<=n;j++){
				if(a[j]-a[i]<=d){
					g[i].push_back({j,a[j]-a[i]});
					g[j].push_back({i,a[j]-a[i]});
				}
			}
		}
		cout<<0<<"\n";
	}
	return 0;
}
