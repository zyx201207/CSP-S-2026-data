#include<bits/stdc++.h>
using namespace std;
const int N=1000005;
int c,t,n,k;
vector<int> f[N];
int main(){
	freopen("hub.in","r",stdin);
	freopen("hub.out","w",stdout);
	cin>>c>>t;
	for(int i=1;i<=t;i++){
		cin>>n>>k;
		for(int i=1;i<=n-1;i++){
			int u,v;
			cin>>u>>v;
			f[u][v]=1;
		}
		cout<<f[1][1]%2<<endl;
	}
	return 0;
}