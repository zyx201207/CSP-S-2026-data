#include<bits/stdc++.h>
using namespace std;
int a[2000005];
int main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	int c,t;
	cin>>c>>t;
	while(t--){
		memset(a,0,sizeof(a));
		int n,d;
		scanf("%d",&n);
		for(int i=1;i<=n;i++){
			scanf("%d",&a[i]);
		}
		int cha=a[2]-a[1];
		if(d>=2*cha && d<3*cha){
			cout<<n-2<<endl;
		}else{
			cout<<0<<endl;
		}
	}
	return 0;
}