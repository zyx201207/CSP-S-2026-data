#include<bits/stdc++.h>
using namespace std;
int c,t,m,a[100000],k,s;
int main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	cin>>c>>t;
	for(int i=1;i<=t;t++){
		cin>>m>>k;
		for(int j=1;j<=m;j++) cin>>a[j];
		for(int j=m;j>=1;j--){
			for(int z=1;z<=m;z++)
				if(a[j]-a[z]==k+1) s++;break;
		}		
		cout<<s<<endl;
	}
	return 0;
}
