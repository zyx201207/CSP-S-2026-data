#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	int t,len=0,ans=0;
	cin>>t;
	string a;
	for(int i=1;i<=t;i++){
		int e;
		char b;
		cin>>e>>b;
		for(int j=1;j<=e;j++){
			a=a+b;
			len++;
		}
	}
	for(int i=0;i<=len/2;i++){
		int j=len-i-1;
		if(a[i]!=a[j])ans++;
	}
	cout<<ans;
}
