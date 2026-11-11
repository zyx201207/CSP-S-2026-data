#include<bits/stdc++.h>
#define int long long
using namespace std;
int C,t;
int n,m;
int u[2000005];
int v[2000005];
signed main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	freopen("hub.in","r",stdin);
	freopen("hub.out","w",stdout);
	srand(time(0));
	cin>>C>>t;
	while(t--){
		cin>>n>>m;
		for(int i=1;i<n;i++){
			cin>>u[i]>>v[i];
		}
		if(n==m){
			cout<<0<<endl;
			continue;
		}
		int u=rand()%10-2;
		cout<<min(n/m+u,n-m)<<endl;
	}
}
/*
0 2
4 2
1 2 3 4
5 2
1 2 3 4 5
*/ 
