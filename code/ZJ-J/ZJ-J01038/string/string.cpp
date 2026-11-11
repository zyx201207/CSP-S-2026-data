#include<bits/stdc++.h>
using namespace std;
#define int long long
int n,a;
string s;
char c;
bool hw(string s){
	int ls=s.size();
	bool flag=true;
	for(int i=0;i<ls;i++){
		if(s[i]!=s[ls-i-1]){
			flag=false;
			break;
		}
	}
	return flag;
}
int hw2(string s){
	int ls=s.size(),ans=0;
	for(int i=0;i<ls;i++){
		if(s[i]!=s[ls-i-1]){
			ans++;
			s[ls-i-1]=s[i];
		}
	}
	return ans;
}
signed main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	if(n==1){
		cout<<0;
		return 0;
	}
	for(int i=1;i<=n;i++){
		cin>>a>>c;
		for(int j=1;j<=a;j++) s+=c;
	}
	if(hw(s)){
		cout<<0;
		return 0;
	}
	cout<<hw2(s);
	return 0;
}