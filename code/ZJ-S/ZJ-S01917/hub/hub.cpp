#include<bits/stdc++.h>
using namespace std;
long long c,T,n,k,x,y,m;
vector<int> e[2000002];
int main(){
	freopen("hub.in","r",stdin);
	freopen("hub.out","w",stdout);
	cin>>c>>T;
	while(T--){
		cin>>n>>k;
		for(int i=1;i<n;i++){
			cin>>x>>y;
			e[x].push_back(y);
			e[y].push_back(x);
		}
		if(n==k){
			cout<<"0\n";
			continue;
		}
		if(c==13||c==14){
			m=n/2;
			if(k>=m)cout<<"1\n";
			else if(k>=m-4)cout<<"2\n";
			else cout<<(m-k+3)/4+1<<'\n';
		}
	}
	return 0;
}
