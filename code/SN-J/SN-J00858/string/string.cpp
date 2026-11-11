#include<bits/stdc++.h>
using namespace std;

int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	int n;
	string s1;
	string s2;
	string s;
	cin>>n;
	long long num=0,ans=0;
	for(int i=1;i<n;i++){
		cin>>s1[i]>>s2[i];
		num+=s1[i];
	}
	for(int i=1;i<=n;i++){
		for(int j=1;j<s1[i];j++){
			s[s1[i-1]+j]=s2[i];
		}
	}
	if(num%2==0){
		for(int i=0;i<=num/2;i++){
			if(s[1+i]!=s[num-i]) ans++;
		}
	}
	if(num%2!=0){
		for(int i=0;i<(num+1)/2;i++){
			if(s[(num+1)/2+i] != s[(num+1)/2-i]) ans++;
		}
	}
	cout<<"0";
	return 0;
}
