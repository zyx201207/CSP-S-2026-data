#include <bits/stdc++.h>
using namespace std;
long long c,n,q,a[2111111],d,nl; 
int main() {
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	cin>>c>>q;
	while(q--){
		cin>>n>>nl;
		for(int i=1;i<=n;i++){
			cin>>a[i];
		}
		
		if(n>1){
		    d=a[2]-a[1];
				
		    nl=nl/d;
		    if(nl<=1){
		    	cout<<0<<endl;
		    	continue;
			}
		}else{
			cout<<0<<endl;
			continue;
		}
		cout<<max(n-2*nl+1,(long long)0)<<endl;
	}
	return 0;
}
