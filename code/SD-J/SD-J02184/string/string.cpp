#include<bits/stdc++.h>
using namespace std;
int ans;
string s,s1,s2;
int main(){
	ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	int n;
	cin>>n;
	for(int i=0;i<n;i++){
		int a;
		char c;
		cin>>a>>c;
		for(int j=0;j<a;j++)s+=c;
	}
	int l=s.size()/2;
	for(int i=0;i<l;i++)s1+=s[i];
	reverse(s1.begin(),s1.end());
	if(s.size()%2==0)for(int i=l;i<s.size();i++)s2+=s[i];
	else for(int i=l+1;i<s.size();i++)s2+=s[i];
	for(int i=0;i<l;i++)if(s1[i]!=s2[i])ans++;
	cout<<ans;
	return 0;
}
//不会写正解，只好暴力拿68 
