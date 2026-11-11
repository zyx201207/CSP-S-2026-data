#include<bits/stdc++.h>
#define int long long
using namespace std;
int n,b;
char  d;
string c;
int hw(string s){
	string a="";
	for(int i=s.size()-1;i>=0;i--){
		a+=s[i];
	}
	if(a==s) return 1;
	else return s.size()/2;
}
signed main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>b>>d;
		for(int j=1;j<=b;j++){
			c+=d;
		}
	}
	if(hw(c)==1) cout<<0;
	else cout<<hw(c);
	return 0;
}

