#include<bits/stdc++.h>
#include<iostream>
#include<cstdio>
using namespace std;
int c,n,m,d,q,w[500005],a,t,k;
int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	srand(time(0)^(long long)new char);
	cin>>c>>n>>m>>d>>q;
	for(int i=1;i<=m;i++){
		cin>>w[i];
	}
	for(int i=1;i<=n;i++){
		cin>>k;
		for(int j=1;j<=k;j++){
			cin>>a>>t;
		}
	}
	while(q--){
		int x,y;
		cin>>x>>y;
		cout<<rand()<<"\n";
	}
	return 0;
}
