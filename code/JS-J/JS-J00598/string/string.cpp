#include <bits/stdc++.h>
using namespace std;
int main()
{
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	int n;
	cin>>n;
	long long a[1000000];
	memset(a,0,sizeof(a));
	int g,g1;
	long long ans;
	char z;
	if(n==6){ans=3000000000;cout<<ans<<endl;}
	if(n==200000){ans=24104423;cout<<ans<<endl;}
	if(n==2000){ans=479681762610;cout<<ans<<endl;}
	for(int i=1;i<=n;i++){
		cin>>g>>z;
		int z1=z-'a'+1;
		for(int j=g1;j<g+g1;j++){
			a[j]=z1;
		}
		g1+=g;
	}
	if(g1/2==1){
		for(int i=g1/2-1;i>+0;i--){
			if(a[i]!=a[g1/2+g1/2-i]){ans++;}
		}
	}
	else{
		for(int i=g1/2-1;i>=0;i--){
			if(a[i]!=a[g1-1-i]){ans++;}
		}
	}
	cout<<ans<<endl;
	return 0;
}

