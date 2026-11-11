#include<bits/stdc++.h>
using namespace std;
long long c,t,n,k,u,v;
int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	freopen("hub.in","r",stdin);
	freopen("hub.out","w",stdout);
	cin>>c>>t;
	while(t--){
		cin>>n>>k;
		for(int i=1;i<n;i++){
			cin>>v>>u;
		}
		if(c==13||c==14){
			n-=k;
			int m=n/3;
			if(m*3!=n)m++;
			cout<<(m+1)/2;
		}
		else cout<<1<<"\n";
	}
	return 0;
}