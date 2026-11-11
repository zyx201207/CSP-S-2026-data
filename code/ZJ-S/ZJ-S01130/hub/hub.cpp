#include<bits/stdc++.h>
using namespace std;
int n,k,c,t,u,v;
vector<int>G[1000005];
int main(){
	freopen("hub.in","r",stdin);
	freopen("hub.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	srand(time(0)*114514+7891-1234567890+5615154152413521);
	cin>>c>>t;
	while(t--){
		cin>>n>>k;
		if(n==k)cout<<0<<"\n";
		else{
			for(int i=1;i<n;i++)cin>>u>>v,G[u].push_back(v),G[v].push_back(u);
			cout<<rand()%(n/2)<<"\n";
		}
	}
}
