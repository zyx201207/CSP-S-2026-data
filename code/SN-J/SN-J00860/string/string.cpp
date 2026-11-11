#include<bits/stdc++.h>
using namespace std;
#define int long long
int n,x;
char a;
string s1="";
string s2="";
int cnt=0;
signed main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>x>>a;
		for(int j=1;j<=x;j++){
			s1+=a;
		}
	}
	for(int i=s1.size()-1;i>=ceil(s1.size()/2);i--){
		s2+=s1[i];
	}
	
	for(int i=0;i<s2.size();i++){
		if(s1[i]!=s2[i])cnt++;
	}
	cout<<cnt;
	return 0;
}


