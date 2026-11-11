#include<iostream>
#include<cmath>
#include<algorithm>
#include<vector>
using namespace std;
typedef long long ll;
const int N=5005;
struct node{
	int y,z;
};
int c,t;
int n,d;
int x[N];
vector<node> g[N];
void dfs()
int main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	cin>>c>>t;
	while(t--){
		for(int i=1;i<=n;i++)x[i]=0;
		cin>>n>>d;
		for(int i=1;i<=n;i++)cin>>x[i];
		for(int i=1;i<=n;i++)
			for(int j=1;j<=n;j++)
				if(i!=j&&x[j]-x[i]<=d&&x[j]-x[i]>=-d){
					g[i].push_back({j,abs(x[i]-x[j])});
					g[j].push_back({i,abs(x[i]-x[j])});
				}
		dfs(1);
	}
	return 0;
} 
