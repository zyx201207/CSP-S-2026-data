#include<bits/stdc++.h>
using namespace std;
const int MAXN=5e5+5;
typedef long long ll;
int w[MAXN];
int t[MAXN];
int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	int n,m,d,q,c;
	cin>>c>>n>>m>>d>>q;
	for(int i=1;i<=m;i++)cin>>w[i];
	for(int i=1;i<=n;i++){
		int num;
		cin>>num;
		for(int i=1;i<=num;i++){
			int k;
			cin>>k;
			cin>>t[k];
		}
	} 
	while(q--){
		int u,v;
		cin>>u>>v;
		cout<<w[u]+w[v]+t[u]+t[v]+t[4]<<endl;
	}
	return 0;
}