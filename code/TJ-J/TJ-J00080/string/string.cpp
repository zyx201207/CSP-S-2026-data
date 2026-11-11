#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	string s="";
	int n;
	cin>>n;
	for(int i=1;i<=n;i++){
		int times;
		char num;
		cin>>times>>num;
		for(int j=1;j<=times;j++){
			s+=num;
		}
	}
	int l=s.size();
	int cnt=0;
	for(int i=0;i<l;i++){
		if(s[i]!=s[l-i-1]){
			s[l-i-1]=s[i];
			cnt++;
		}
	}
	cout<<cnt;
	return 0;
} 
