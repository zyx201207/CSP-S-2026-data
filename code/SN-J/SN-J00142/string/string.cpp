#include<bits/stdc++.h>
using namespace std;

int n,sum=0;
string s,s1;

int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	for(int i=0;i<n;i++){
		int num;
		char a;
		cin>>num>>a;
		for(int j=0;j<num;j++){
			s+=a;
		}
	}
	for(int i=s.size()-1;i>=0;i--){
		s1+=s[i];
	}
	if(s==s1){
		cout<<0;
		return 0;
	}
	for(int i=0;i<s.size()/2;i++){
		if(s[i]!=s[s.size()-1-i]){
			sum++;
		}
	}
	cout<<sum;
	
	return 0;
} 
