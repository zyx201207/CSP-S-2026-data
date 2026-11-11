#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	long long n,x=0;
	string s;
	cin>>n;
	long long v;
	char c;
	for(int i=0;i<n;i++){
		cin>>v>>c;
		for(int i=0;i<v;i++){
			s+=c;
		}
	}
	for(int i=0;i<s.size();i++){
		if(s[i]!=s[s.size()-1-i]){
			x++;
			s[i]=s[s.size()-1-i];
		} 
	}
	cout<<x;
	return 0;
} 
