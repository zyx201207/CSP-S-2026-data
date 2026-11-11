#include<bits/stdc++.h>

using namespace std;
string s;
int n,ans=0,an2=0;
int main()
{
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
//	
	ios::sync_with_stdio(0);
	cin.tie(nullptr);
	cout.tie(nullptr);
	cin>>n;
	for(int i=1;i<=n;i++) {
		int m;
		char x;
		cin>>m>>x;
		s+=string(m,x);
	}
	string s1,s2;
	for(int i=s.size()-1;i>s.size()/2;i--) s1+=s[i];
	for(int i=s.size()/2;i<s.size();++i) s1+=s[i];
		
	for(int i=0;i<s.size()/2;++i) s2+=s[i];
	for(int i=s.size()/2;i>=0;--i) s2+=s[i];
	if(s1==s||s2==s) {
		cout<<0;
		return 0;
	}
	for(int i=0;i<s.size();++i){
		if(s[i]!=s1[i]) ++ans;
		if(s[i]!=s2[i]) ++an2;
	}
	
		
	
	cout<<min(ans,an2);

 	//32
	return 0;
}

