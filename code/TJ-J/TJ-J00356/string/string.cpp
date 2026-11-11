#include <bits/stdc++.h>
using namespace std;
string rv(string a){
	string b="";
	for(int i=a.size();i>=0;i--){
		b+=a[i];
	}
	return b;
}
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	string s;
	int cnt=0,a,n;
	char c;
	cin>>n;
	
	for (int i=1;i<=n;i++){
		cin>>a>>c;
		for (int i=1;i<=a;i++){
			s=s+c;
		}
	}
	int m=s.size();
	string s1=s,s2=s;
	if(s==rv(s)){cout<<"0";
	}else {
	for(int i=m;i<=m/2;i--){
		if(s[i-1]!=s[m-i]){
			s[i-1]=s[m-i];
			cnt++;
		}
	}}
	cout<<cnt;
	return 0;
}
