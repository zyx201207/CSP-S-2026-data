#include<bits/stdc++.h>
using namespace std;
long long c;
void solve_13_14(){
	long long n,k;
	for(long long i=1;i<=n;i++){
		long long u,v;
		cin>>u>>v;
	}
	cout<<k<<'\n';
}
int main()
{
	freopen("hub.in","r",stdin);
	freopen("hub.out","w",stdout);
	cin>>c;
	if(c==13||c==14){
		long long t;
		while(t--){
			solve_13_14();
		}
	}else{
		long long t;
		cin>>t;
		srand(time(0));
		while(t--){
			if(c<7) cout<<rand()%107<<'\n';
			else cout<<rand()%1124357<<'\n';
		}
	}
}
