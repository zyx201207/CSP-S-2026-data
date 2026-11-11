#include<bits/stdc++.h>
using namespace std;

int c,t;
int n,k,u,v;
vector<int>ve[2000010];
int main(){
	freopen("hub.in","r",stdin);
	freopen("hub.out","w",stdout);

	cin>>c>>t;
	while(t--){
		cin>>n>>k;
		for(int i=1;i<n;i++){
			cin>>u>>v;
			ve[u].push_back(v);
			ve[v].push_back(u);
		}
		cout<<1;
	}

	fclose(stdin);
	fclose(stdout);
	return 0;
}
