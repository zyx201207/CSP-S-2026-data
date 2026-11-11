#include <bits/stdc++.h>
using namespace std;
int a[200005];
char c[200005];
string s="";
int n; 
string reve(string s){
	string s1;
	for(int i=s.size();i>=0;i--){
		s1[n-i+1]=s[i];
	}
	return s1;
}
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i]>>c[i];
		for(int j=1;j<=a[i];j++){
			s+=c[i];
		}
	}
	if(s==reve(s)){
		cout<<0;
		return 0;
	}
	int cnt=0;
	for(int i=0;i<s.size()/2;i++){
		if(a[i]!=a[n-i+1]){
			cnt++;
		}
	}
	cout<<cnt;
	return 0;
}
