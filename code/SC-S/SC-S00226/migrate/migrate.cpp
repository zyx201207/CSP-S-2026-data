#include<bits/stdc++.h>
using namespace std;
int c,t,n;
long long d,a[200005];
int main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	cin>>c>>t;
	for(int i=1;i<=t;i++){
		cin>>n>>d;
		for(int k=1;k<=n;k++){
			cin>>a[k];
			if(a[k]-a[k-1]>d){
				cout<<0<<endl;
				break;
			}
			if(a[k]-a[k-1]==a[k-1]-a[k-2]&&k>=2){
				
			}
		}
		
	}
	return 0;	
}