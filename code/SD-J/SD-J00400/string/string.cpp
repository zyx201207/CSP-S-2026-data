#include<bits/stdc++.h>
using namespace std;
int n,a[200002],dy=0,z=0,ans=0,dydy=0;
char c[200002],s[200002];
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i]>>c[i];
		z+=a[i];
		c[0]=c[1];
		a[0]=a[1];
		if(c[i]==c[i-1]) dy++;
		if(a[i]==a[i-1]) dydy++;
		for(int j=1;j<=a[i];j++){
			s[j]=c[i];
		}
	}
	if(dy==n||n==1){
		cout<<"0";
		return 0;
	}
	if(dydy==n){
		cout<<n/2*a[1];
		return 0;
	}
	for(int i=1;i<=z/2;i++){
		if(s[i]!=s[z-i+1]) ans++;
	}
	cout<<ans;
	return 0;
}
