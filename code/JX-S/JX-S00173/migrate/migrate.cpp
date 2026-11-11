#include<bits/stdc++.h>
using namespace std;
int c,t,n,d,a[2000008],ans;
int main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	cin>>c>>t;
	for(int i=1;i<=t;i++){
		cin>>n>>d;
		for(int j=1;j<=n;j++)
			cin>>a[i];
		if(a[2]-a[1]>d)cout<<ans<<endl;
		else{
			if(n<4)cout<<ans<<endl;
			else cout<<n-4+1<<endl;
		} 
	}
	return 0;
}	

