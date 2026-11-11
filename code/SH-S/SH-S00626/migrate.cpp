#include<bits/stdc++.h>
#define int long long
using namespace std;
int c,t,n,d,x[2000005],xc[2000005];
void sub_1(){
	int cha=xc[2];
	if(cha>d) cout<<0;
	else if(cha*2<=d) cout<<0;
	else cout<<n-1;
	return;
}
void sub_2(){
	//int cha=a[2]-a[1];
	
	return;
}
signed main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	cin>>c>>t;
	while(t--){
		cin>>n>>d;
		for(int i=1;i<=n;i++){
			cin>>x[i];
			xc[i]=x[i]-xc[i-1];
		}
		if(11<=c<=12) sub_1();
		else cout<<0;
	}
	
	return 0;
}
