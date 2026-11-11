#include<bits/stdc++.h>
using namespace std;
int t,n,c,ans=0,d,x[5000010],a,y[5000010],m=0,l=0,v=0,u=0;
int main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	cin>>c>>t;
	for(int i=1;i<=t;i++){
		cin>>n>>d;
	}
	for(int i=0;i<n;i++){
		cin>>x[i];
		while(d--){
			for(int j=1;j<=n;j++){
				if(x[i]-x[j]<=d||n<3){
					cout<<'0';
				}
				else if(y[i]==u&&y[m]==v||1<=l<=m-1){
					y[l]==y[l+1];
					ans++;
				}
			}
			ans++;
		}
	}
	cout<<ans<<endl;
	return 0;
}
