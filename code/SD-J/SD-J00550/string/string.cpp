#include<bits/stdc++.h>
using namespace std;
int n;
string s;
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++){
		int a;
		char c;
		cin>>a>>c;
		for(int j=1;j<=a;j++){
			s+=c;
		}
	}
	long long l=s.size(),ans=0;
	for(int i=0;i<=l/2;i++){
		if(s[i]!=s[l-1-i]){
			ans++;
		}
	}	
	cout<<ans;
	return 0;	
} 
