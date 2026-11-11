#include<bits/stdc++.h>
using namespace std;
int main(){
//	freopen("string.in","r",stdin);
//	freopen("string.out","w",stdout);
	int n,a,cnt=0;
	char c;
	string s;
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a>>c;
		while(a--) s+=c;
	}
	char cs=s[0];
	int f=1;
	for(int i=0;i<s.size();i++){
		if(s[i]!=cs) f=0;
	}
	if(f==1){
		cout<<0;
		return 0;
	}
	for(int i=0;i<s.size()/2;i++){
		if(s[i]!=s[s.size()-i]) cnt++;
	}
	cout<<cnt;
	return 0;
}