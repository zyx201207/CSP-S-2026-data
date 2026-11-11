#include<bits/stdc++.h>
using namespace std;
const int N=2e6+10;
int x[N];
int main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	int c,T,n,d;
	cin>>c>>T;
	while(T--){
		cin>>n>>d;
		for(int i=1;i<=n;i++) cin>>x[i];
		if(n==1||d<x[2]-x[1]){
			cout<<0<<'\n';
			continue;
		}
	}
	return 0;
}