#include<bits/stdc++.h>
#define rep(i,a,b) for(int i=(a);i<=(b);i++)
#define pre(i,a,b) for(int i=(a);i>=(b);i--)
using namespace std;

int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	int n;
	int a1[10001];
	char b1[10001];
	string a;
	int ans;
	cin>>n;
	rep(i,1,n){
		cin>>a1[i]>>b1[i];
		ans+=a1[i];
	}
 	rep(i,1,n){
		if(b1[i]==b1[i+1]) ans=0;
		if(n==1) ans=0;
	}
	cout<<ans/2;
	fclose(stdin);
	fclose(stdout);

	return 0;
}

