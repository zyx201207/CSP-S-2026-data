#include<bits/stdc++.h>
using namespace std;
#define ll long long
ll T,n,k,i,a[2000005],cha;
int main(){
	freopen("migrate4.in","r",stdin);
	freopen("migrate.out","w",stdout);
	
	cin>>T>>T;
	while(T--){
		cin>>n>>k;
		for(i=1;i<=n;i++)
		cin>>a[i];
		cha=a[2]-a[1];
		if(2*cha<=k&&k<3*cha)
		cout<<n-3<<endl;
		else
		cout<<0<<endl;
	}
	return 0;
}

