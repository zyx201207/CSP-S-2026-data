#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	long long t,ans=0,n,g;
	string a;
	char c;
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>t>>c;
		for(int q=1;q<=t;q++){
			a+=c;}
			}
	g=a.length();
	for(int i=0;i<g/2;i++){
		if(a[i]!=a[g-i-1])  ans++;
	}
	cout<<ans;
	return 0;
}
