#include<bits/stdc++.h>
using namespace std;
string str1="";
string strh="";
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
	int n;
	cin>>n;
	long long m=0;
	for(int i=1;i<=n;i++){
		int s;
		cin>>s;
		char a;
		cin>>a;
		m+=s;
		for(int i=1;i<=s;i++){
			str1=str1+a;
		}
	}
	for(long long i=str1.size()-1;i>=0;i--){
		strh+=str1[i];
	}
	if(strh==str1){
		cout<<0;
		return 0;
	}
	long long ans=0;
	long long idx=str1.size()-1;
	for(long long i=0;i<str1.size()/2;i++){
		if(str1[i]!=str1[i+idx]){
			ans++;
			idx-=2;
		}
	}
	cout<<ans;


	return 0;
} 
