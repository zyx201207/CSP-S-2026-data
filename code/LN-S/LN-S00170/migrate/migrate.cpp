#include<bits/stdc++.h>
using namespace std;
int c,t;long long a[2000010];
int n,m;
int main(){
    freopen("migrate.in","r",stdin);
    freopen("migrate.out","w",stdout);
    cin>>c>>t;
    while(t--){
		cin>>n>>m;
		for(int i=1;i<=n;i++)cin>>a[i];
		int k=a[2]-a[1],kk=2*(m/k)-1;
		if(m/k==1)cout<<"0"<<endl;
		else{cout<<n-kk<<endl;}
	}
	return 0;
}
