#include<bits/stdc++.h>
using namespace std;
int n;
string s,x,y,a,b;
int ans;
int check(string s){
	for(int i=0;i<s.size();i++){
		a+=s[i];
	}
	for(int i=s.size()-1;i>=0;i--){
		b+=s[i];
	}
	if(a==b) return 1;
	return 0;
}

int main(){
	freopen("string,in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	int a;
	char b;
	for(int i=1;i<=n;i++){
		cin>>a>>b;
		for(int i=1;i<=a;i++){
			s+=b;
		}
	}
	if(check(s)){
		cout<<0;
		return 0;
	}
	if(s.size()==2){
		if(s[0]!=s[1]) {
			cout<<1;
			return 0;
		}
		else {
			cout<<0;
			return 0;
		}
	}
	int xx=s.size()/2;
	for(int i=0;i<xx;i++){
		x+=s[i];
	}
	for(int i=s.size()-1;i>=s.size()-xx;i--){
		y+=s[i];
	}
	for(int i=0;i<xx;i++){
		if(x[i]!=y[i]) ans++;
	}
	cout<<ans;
	return 0;
}
