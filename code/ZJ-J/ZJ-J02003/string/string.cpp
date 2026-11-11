#include <bits/stdc++.h>
using namespace std;
int main(){
	int n;
	int cnt=0;
	string s="",s1="";
	cin>>n;
	long a[20005];
	char c[20005];
	for(int i=1;i<=n;i++){
		cin>>a[i]>>c[i];
	}for(int i=1;i<=n;i++){
		for(int i=1;i<=a[i];i++){
			s+=c[i];
		}
	}for(int i=s.size()-1;i>=0;i--){
		s1+=s[i];
	}if(s1==s){
		cout<<0;
	}else{
		for(int i=0;i<s.size();i++){
			if(s[i]!=s1[i]){
				s1[i]=s[i];
				s[s.size()-1-i]=s[i];
				cnt+=1;
			}
		}
		cout<<cnt-1;
	}
	return 0;
}
