// ~60
#include<bits/stdc++.h>
#define int long long
using namespace std;
int n;
int l;
string s;
signed main(){
	freopen("string.in","r",stdin);freopen("string.out","w",stdout);
	ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	cin>>n;
	int a;char b;
	int l=0;
	for(int i=0;i<n;i++){
		cin>>a>>b;
		for(int j=0;j<a;j++)s+=b;
	}
	l=s.size();
	int ans=0;
	for(int i=0;i<=l/2;i++){
		if(s[i]!=s[l-i-1])ans++;
	}
	cout<<ans<<endl;
	return 0;
}
