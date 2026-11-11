#include <bits/stdc++.h>
using namespace std;

int huiwen(string s){
	string s1="";
	int n=0;
	for(int i=s.size()-1;i>=0;i--){
		s1 += s[i];
	}
	if(s==s1){
		return n;
	}
}
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	string c,S= "";
	int a,n,num;
	cin>>n;
	for(int i=0;i<n;i++){
		cin>>a>>c;
		for(int j=0;j<a;j++){
			S += c;
		}
	}
	num = huiwen(S);
	cout<<num;
	return 0;
}
