#include<bits/stdc++.h>
using namespace std;
int c,t,n,d,a[2000005];
void b(int x, int y){
	
}
int main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	cin>>c>>t;
	while(t--){
		cin>>n>>d;
		for(int i=1;i<=n;i++){
			cin>>a[i];
		} 
		int u,v;
		for(int i=1;i<=n;i++){
			for(int j=2;j<=n;j++){
				u=a[i];
				v=a[j];
				if(a[j]-a[i]!=0 && a[j]-a[i]<=d){
					b(i,j);
				}
			} 
		} 
	}
	return 0;
}
