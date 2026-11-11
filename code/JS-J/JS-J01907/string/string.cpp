#include<bits/stdc++.h>
using namespace std;
long long n,a[210000],pd,js;
char c[210000];
string s;
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	pd=1;
	js=0;
	for(int i=1;i<=n;i++){
		cin>>a[i]>>c[i];
		c[0]=c[1];
		s+=c[i];
		if(c[i]!=c[i-1])
			pd=0;
	}
	if(pd==1){
		cout<<1;
		return 0;
	}
	if(n==1){
		cout<<0;
		return 0;
	}
	if(n==2){
		cout<<min(a[1],a[2]);
		return 0;
	}
	for(int i=0;i<=int(s.size()/2-int(s.size()%2==0));i++){
		if(s[i]!=s[s.size()-i-1])
			js+=1;
	}
	cout<<js*a[1];
	return 0;//Score||Treat!
}
