#include<bits/stdc++.h>
using namespace std;
int n,m;
int maxn=-1;
string er(int t){
	string s="",a;
	while(t!=0){
		s+=(t%2+'0');
		t/=2;
	}
	a=s;
	for(int i=0;i<a.length();i++){
		s[i]=a[a.length()-1-i];
	}
	return s;
}
int ten(string s){
	int numn=0;
	for(int i=0;i<s.length();i++){
		if(s[i]=='0')continue;
		int t=1;
		for(int j=0;j<s.length()-1-i;j++){
			t*=2;
		}
		numn=numn+t;
	
	}
	return numn;
}
string andn(string a,string b){
	string t="",c;
	for(int i=0;i<min(a.length(),b.length());i++){
		if(a[a.length()-i-1]=='1'&&b[b.length()-i-1]=='1')t+='1';
		else t+='0';
	}
	c=t;
	for(int i=0;i<c.length();i++){
		t[i]=c[c.length()-1-i];
	}
	return t;
}
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	int a[200005];
	cin>>n>>m;
	if(m==1){
		for(int i=0;i<n;i++){
			int t;
			cin>>t;
			maxn=max(maxn,t);
		}
		cout<<maxn;
		return 0;
	}
	if(m==n){
		cin>>a[0];
		string z=er(a[0]);
		for(int i=1;i<n;i++){
			int t;
			cin>>t;
			z=andn(er(t),z);
		}
		cout<<ten(z);
	}
	for(int i=0;i<n;i++){
		cin>>a[i];
	}
	for(int i=0;i<n-1;i++){
		for(int j=i+1;j<n;j++){
			maxn=max(maxn,ten(andn(er(a[i]),er(a[j]))));
		}
	}
	cout<<maxn;
	return 0;
} 
