#include<bits/stdc++.h>
using namespace std;
#define FILENAME "card"
int n,m,a[5000001],ans[3000001];
vector<int> game;
int pos[5000001];

int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	freopen(FILENAME ".in","r",stdin);
	freopen(FILENAME ".out","w",stdout);

	cin>>n>>m;

	for(int i=1,k;i<=n;i++){
		cin>>k;
		ans[k]++;
	}
	for(int i=1;i<=m;i++) cout<<ans[i]<<' ';

	return 0;
}