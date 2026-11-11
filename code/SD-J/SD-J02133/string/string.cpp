#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	string s="";
	long long k,n=0;
	for(long i=0;i<k;i++)
	{
		long long a;
		char c;
		cin>>a>>c>>c;
		for(long long i=0;i<a;i++)
		s+=c;
		n+=a;
	}
	int mun=0;
	for(int i=0;i<(n+1)/2;i++)
	if(s[i]!=s[n-i+1])
	mun++;
	cout<<mun;
	return 0;
}

