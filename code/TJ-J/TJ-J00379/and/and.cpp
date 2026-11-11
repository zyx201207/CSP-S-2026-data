#include <bits/stdc++.h>
using namespace std;
string yu(int a,int b){
	string a1="",b1="",c="";
	while(a>0){
		a1+=a%2+'0';
		a/=2;
	}
	while(b>0){
		b1+=b%2+'0';
		b/=2;
	}
	reverse(a1.begin(),a1.end());
	reverse(b1.begin(),b1.end());
	if(b1.size()<a1.size()) swap(a1,b1);
	for(int i=0;i<min(a1.size(),b1.size());i++){
		if(a1[i]==b1[i]) c[i]='1';
		else c[i]='0';
	}
	for(int i=min(a1.size(),b1.size());i<max(a1.size(),b1.size());i++){
		if(b1[i]=='0') c[i]='1';
	}
	return c;
}
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	int n,m;
	cin>>n>>m;
	int a[n];
	for(int i=0;i<n;i++){
		cin>>a[i];
	}
	sort(a,a+n);
	if(m==1) {
		cout<<a[n-1];
	}
	else{
		cout<<a[n/2+1];
	}
	return 0;
}
