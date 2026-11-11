#include<bits/stdc++.h>
using namespace std;//compare the first half with the other! Do it two times and use min(ans1,ans2)!
int n,ans=0;
string s;
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	for(int i=0;i<n;i++){
		int a;
		char c;
		cin>>a>>c;
		for(int j=0;j<a;j++){
			s+=c;
		}
	}
	int sz=s.size();
	for(int i=0;i<sz/2;i++){
		if(s[i]!=s[sz-i-1])ans++;
	}
	cout<<ans;
	return 0;
}
