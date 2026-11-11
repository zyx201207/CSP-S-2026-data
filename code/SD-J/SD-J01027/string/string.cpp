#include<bits/stdc++.h>
using namespace std;
int cnt;
string s,s1;
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	int n;
	cin>>n;
	for(int i=1;i<=n;i++){
		int x;
		string ss;
		cin>>x>>ss;
		for(int i=1;i<=x;i++){
			s+=ss;
		}
	}
	cout<<s1;
	for(int i=s.size()-1;i>=0;i--){
		s1+=s[i];
	}
	for(int i=0;i<s.size();i++){
		if(s1[i]!=s[i]) cnt++;
	}
	cout<<cnt/2;
	return 0;
}
