#include<bits/stdc++.h>
using namespace std;
char a[99999999];
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	int n,len=0,ans=0;
	cin>>n;
	for(int i=1;i<=n;i++){
		int x;
		char s;
		cin>>x>>s;
		for(int j=1;j<=x;j++){
			a[++len]=s;
		}
	}
	for(int i=1;i<=len/2;i++){
		if(a[i]!=a[len-i+1]) ans++;
	}
	cout<<ans;
	return 0;
}