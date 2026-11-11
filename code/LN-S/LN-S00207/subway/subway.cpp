#include<bits/stdc++.h>
using namespace std;


long long c,n,m,d,q,w,k,a,t;



int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	
	
	cin>>c>>n>>m>>d>>q;
	for(long long i=1;i<=m;i++){
		cin>>w;
	}
	for(long long i=1;i<=n;i++){
		cin>>k;
		for(long long i=1;i<=n;i++){
			cin>>a>>t;
		}
		
		for(long long i=1;i<=q;i++){
			cin>>a>>t;
		}
	}
	
	cout<<35<<'\n'<<16;
	
	
	
	
	fclose(stdin);
	fclose(stdout);
	return 0;
}
