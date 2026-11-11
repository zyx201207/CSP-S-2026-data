#include <bits/stdc++.h>
using namespace std;

int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	
	//ios::sync_with_stdio(false);
	//cin.tie(nullptr);
	
	long long n,m,c=0,i,j;
	string s,s1;
	cin>>n;
	for(i=0;i<n;i++)
	{
		cin>>m;
		cin>>s1;
		for(j=0;j<m;j++)
		{
			s+=s1;
		}
	}
	for(i=0,j=s.size()-1;i<(s.size()+1)/2,j>=(s.size()+1)/2;i++,j--)
	{
		if(s[i]!=s[j])
			c++;
	}
	cout<<c;
	return 0;
}
