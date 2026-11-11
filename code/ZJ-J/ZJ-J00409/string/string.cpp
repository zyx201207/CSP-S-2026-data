#include<bits/stdc++.h>
using namespace std;
int a[200010];
char k[200010];
long long l[200010];
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	string s;
	int n;
	cin>>n;
	for(int i=1;i<=n;i++){
		int x;
		string t;
		cin>>x>>t;
		for(int j=1;j<=x;j++)s+=t;
	}
	long long ans=0;
	for(int i=0;i<s.size()/2;i++){
		if(s[i]!=s[s.size()-i-1])ans++;
	}
	cout<<ans;
	return 0;
}