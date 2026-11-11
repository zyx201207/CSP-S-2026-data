#include <bits/stdc++.h>
using namespace std;
const int N=2e5+10;
long long n,ans,a[N],f=1;
char c[N];
int main(){
	freopen("string.in",0,stdin);
	freopen("string.out",0,stdout);
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i]>>c[i];
		ans+=a[i];
	}
	for(int i=1;i<n;i++){
		if(c[i]!=c[i+1]) f=0;
	}
	if(ans%2==0) ans=ans/2;
	else ans=(ans-1)/2;
	if(n==1||f==1){
		cout<<0;
	}else{
		cout<<ans;
	}
	return 0;
}
