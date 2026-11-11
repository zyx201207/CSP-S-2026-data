#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	int c,t,n,d,shuliang=0;
	cin>>c>>t>>n>>d;
	int x;
	for(int i=0;i<n;i++){
		cin>>x;
	}
	for(int j=0;j<n;j++){
		if(x<=d){
			shuliang=shuliang+1;
		}
	}
		cout<<shuliang;
		return 0;
	}

	
	