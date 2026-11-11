#include<bits/stdc++.h>
using namespace std;
string huiwen(string d){
	string ans="";
	for(int i=d.size()-1;i>=0;i--){
		ans+=d[i];
	}
	return ans;
}
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	int n;
	string s="";
	cin>>n;
	for(int i=1;i<=n;i++){
		int b;
		cin>>b;
		string a;
		cin>>a;
		for(int i=1;i<=b;i++) s+=a;
	}
	long long cnt=0;
	for(int i=0;i<s.size();i++){
		string ss=huiwen(s);
		if(ss!=s&&s[i]!=s[s.size()-1-i]){
			s[s.size()-1-i]=s[i];
			cnt++;
		}
	}
	cout<<cnt;
	return 0;
}
