#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	long long n;
	cin>>n;
	string s="";
	while(n--){
		long long x;
		char c;
		cin>>x>>c;
		for(int i=1;i<=x;i++){
			s+=c;
		}
	}
	string s1=s;
	reverse(s1.begin(),s1.end());
	if(s1==s){
		cout<<0;
		return 0;
	}
	int cnt=s.size()/2;
	s1="";
	string s2="";
	for(int i=0;i<cnt;i++){
		s1+=s[i];
	}
	if(s.size()%2==0){
		for(size_t i=cnt;i<s.size();i++){
			s2+=s[i];
		}
	}else{
		for(size_t i=cnt+1;i<s.size();i++){
			s2+=s[i];
		}
	}
	reverse(s2.begin(),s2.end());
	long long ans=0;
	for(size_t i=0;i<s1.size();i++){
		if(s1[i]!=s2[i]){
			ans++;
		}
	}
	cout<<ans;
	return 0;
}
