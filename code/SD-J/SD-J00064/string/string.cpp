#include<bits/stdc++.h>
using namespace std;
string s;
char c;
int n,a;
long long ans=0;
int main()
{
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a;
		cin>>c;
		for(int i=1;i<=a;i++)	s+=c;
	}
	int n1=s.size()/2;
	for(int i=0;i<n1;i++){
		if(s[i]!=s[s.size()-i-1]){
			s[s.size()-1-i]=s[i];
			ans++;
		}
	}
	cout<<ans;
	return 0;
}
