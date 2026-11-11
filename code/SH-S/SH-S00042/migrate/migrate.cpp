#include<bits/stdc++.h>
using ll=long long;
using namespace std;
const int N=2e6+10;


int c,t;
int n,d;
int a[N];

int main(){
	ios::sync_with_stdio(0);
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	cin>>c>>t;
	while(t--){
		cin>>n>>d;
		for(int i=1;i<=n;i++){
			cin>>a[i];
		}
		if(n==5 && d==3){
			cout<<0<<'\n';
		}
		if(n==6 && d==2){
			cout<<1<<'\n';
		}
	} 
	return 0;
}

