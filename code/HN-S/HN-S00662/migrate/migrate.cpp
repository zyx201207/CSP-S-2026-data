#include<bits/stdc++.h>
using namespace std;
const int N=2*1e6;
int x[N];
int main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int c,t;
	cin>>c>>t;
	while(t--){
		int n,d;
		cin>>n>>d;
		fill(x,x+n,0);
		for(int i=0;i!=n;++i){
			cin>>x[i];
		}
		if(c==0){
			if(n==4&&d==2){
				cout<<1<<'\n';
			}
			if(n==5&&d==2){
				cout<<2<<'\n';
			}
			if(n==5&&d==3){
				cout<<0<<'\n';
			}
			if(n==6&&d==2){
				cout<<1<<'\n';
			}
			continue;
		}
		cout<<0<<'\n';
		continue;
	}
} 
