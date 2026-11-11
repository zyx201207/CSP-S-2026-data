#include <iostream>
#include <cstring>
#include <string>
#include <algorithm>
using namespace std;
const int N = 505;
const int M = 1e3+5;
int k;
int c,n,m,d,q;
int w[M]
struct node
{
	int a[N];
	int t[N];
};
node road[M];
int main()
{
	freopen("subway.in", "r", stdin);
	freopen("subway.out", "w", stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	cin>>c>>n>>m>>d>>q;
	for(int i = 1;i<=m;i++){
		cin>>w[i];
	}
	for(int i= 1;i<=n;i++){
		cin>>k;
		for(int j = 1;j<=k;i++){
			int x,y;
			cin>>x>>y;
		}
	}
	for(int i = 1;i<=q;i++){
		int x,y;
		cin>>x>>y;
		cout<<(x*y)%w[1]<<'\n';
	}
	return 0;
}