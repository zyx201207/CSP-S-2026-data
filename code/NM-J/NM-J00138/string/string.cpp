#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	int n,a;
	char c;
	string s;
	string s1;
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a>>c;
		for(int j=1;j<=a;j++){
			s+=c;
		}
	}
	if(n==1){
		cout<<0;
		return 0;
	}
	for(int i=s.size()-1;i>=0;i--){
		s1+=s[i];
	}
	if(s1==s){
		cout<<0;
		return 0;
	}
	cout<<2;
	return 0;
}
