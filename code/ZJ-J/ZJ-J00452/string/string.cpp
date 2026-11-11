#include<bits/stdc++.h>
using namespace std;
int main()
{
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	string s;
	char c;
	int n,shu,ans=0;
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>shu>>c;
		for(int j=1;j<=shu;j++)s+=c;
	}
	for(int i=0;i<s.size()/2;i++){
		if(s[i]!=s[s.size()-i-1])ans++;
	}
	//cout<<s<<endl;
	cout<<ans;
	return 0;
}