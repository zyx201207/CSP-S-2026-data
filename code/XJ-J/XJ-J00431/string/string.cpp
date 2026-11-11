#include <bits/stdc++.h>
using namespace std;
string reverse_(string s,int n1){
	string s1;
	for(int i=n1-1;i>=0;i--){
		s1+=s[i];
	}
	return s1;
}
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	int n;
	cin>>n;
	string s;
	int n1=0;
	for(int i=0;i<n;i++){
		int a; string b;
		cin>>a>>b;
		string s1;
		n1+=a;
		for(int j=0;j<a;j++){
			s1+=b;
		}
		s+=s1;
	}
	if(reverse_(s,n1)==s) {
	cout<<0;
	return 0;
}
	string l,r;
	for(int i=0;i<n1/2;i++){
		l+=s[i];
	}
	int a1=0;
	if(n1%2==1) a1=1;
	for(int i=n1/2+a1;i<n1;i++){
		r+=s[i];
	}
	int l1,r1;
	int j=n1/2-a1;
	int ans=0;
	for(int i=0;i<n1/2;i++){
		if(l[i] != r[j]) ans++;
		j--;
	}
	cout<<ans;
	return 0;
}