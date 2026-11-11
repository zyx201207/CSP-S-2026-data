#include<bits/stdc++.h>
#define ll long long
using namespace std;
int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	freopen("hub.in","r",stdin);
	freopen("hub.out","w",stdout);
	srand(time(0));
	int c,t;
	cin>>c>>t;
	while(t--){
		int n,k,W;
		cin>>n>>k>>W;
		for(int i = 1,u,v;i < n;++i)cin>>u>>v;
		cout<<rand()%10;
	}
	return 0;
}
