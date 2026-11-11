#include<bits/stdc++.h>
using namespace std;
string s,s1;
long long int n,x,ans;
int main()
{
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>x>>s;
		for(int j=1;j<=x;j++){
			s1+=s;
		}
	}
	int len=s1.size();
	for(int i=0;i<=(len-1)/2;i++){
		if(s1[i]!=s1[len-1-i])ans++;
	}
	cout<<ans;
	return  0;
}
