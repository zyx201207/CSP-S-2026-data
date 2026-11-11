#include<bits/stdc++.h>
#define int long long
using namespace std;
int n,m;
bool A=true,B=true;
int a[500005],s[500005];
signed main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	scanf("%lld%lld",&n,&m);
	for(int i=1;i<=n;i++)scanf("%lld",&a[i]);
	sort(a+1,a+n+1);
	//-----------特殊pts保分-------------
	   if(n==1){
		cout<<1;
		return 0;
	}
	else if(n==2){
		if(abs(a[2]-a[1])<=m) cout<<2;
		else cout<<1;
		return 0;
	}
	for(int i=2;i<=n;i++){
		if(a[i]-a[i-1]!=1)A=false;
		if(i>2 && a[i]-a[i-1]!=a[i-1]-a[i-2])B=false;
	}	
	for(int i=1;i<=n-1;i++)s[i]=s[i-1]+(a[i+1]-a[i])*i;
	for(int i=1;i<=n;i++){
		if(i==n){
			cout<<n;
			break;
		}
		else if(s[i]>m){
			cout<<i;
			break;
		}
	}
	//-----------------------------------
	fclose(stdin);
	fclose(stdout);
	return 0;
}