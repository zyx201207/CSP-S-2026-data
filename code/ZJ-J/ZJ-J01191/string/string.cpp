#include<bits/stdc++.h>
using namespace std;
string s;
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	char t;
	int n,k,ans=0;
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>k>>t;
		for(int j=1;j<=k;j++){
			s+=t;
		}
	}
	for(int i=0;i<s.size()/2;i++){
		if(s[i]!=s[s.size()-1-i])ans++;
	}
	cout<<ans;
	return 0;
}
