#include<bits/stdc++.h>
using namespace std;
int a[5005],c,q,n,t,ans=0,e;
int main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	cin>>c>>q;
	while(q>=1){
		ans++;
		q--;
		cin>>n>>t;
		for(int i=1;i<=n;i++){
			cin>>a[i];
		}
		for(int i=1;i<=n;i++){
			e=0;
		}
		cout<<ans<<endl;
	}
	return 0;
} 
