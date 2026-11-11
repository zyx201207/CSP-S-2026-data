#include<bits/stdc++.h>
using namespace std;
vector<string> s;
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	long long n;
	long long m;
	string a;
	long long sum=0;
	cin>>n;
	for(long long i=1;i<=n;i++)
	{
		cin>>m>>a;
		for(long long j=1;j<=m;j++)
			s.push_back(a);
		sum+=m;
	}
	long long ji=0;
	for(long long i=0;i<sum/2;i++)
	{
		if(s[i]!=s[sum-i-1])
			ji++;
	}
	cout<<ji;
	return 0;
}