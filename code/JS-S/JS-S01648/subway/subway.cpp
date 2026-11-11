#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
int o,n,m,k,q;
ll a[500010],sum;
struct node{
	int x,s;
};
int b[510][50010];
int t[510][50010];
vector<int> v[50010];
int main(){
	srand(time(0));
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	ios::sync_with_stdio(0);
	cout.tie(0),cin.tie(0);
	cin>>o>>n>>m>>k>>q;
	for(int i=1;i<=m;i++) cin>>a[i],sum+=a[i];
	for(int i=1;i<=n;i++){
		cin>>b[i][0];
		for(int j=1;j<=b[i][0];j++){
			cin>>b[i][j]>>t[i][j];
			sum+=t[i][j];
			if(j>1){
				int x=b[i][j-1],y=b[i][j];
				v[x].push_back(y);
				v[y].push_back(x);
			}
		}
	}
	while(q--){
		int s,e;
		cin>>s>>e;
		cout<<rand()%sum<<'\n';
	}
	return 0;
}
