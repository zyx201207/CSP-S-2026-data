#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	int n,cnt;
	string S;
	cin>>n;
	for(int i=1;i<=n;i++)
	{
		long long c;
		char ch;
		cin>>c>>ch;
		for(long long j=1;j<=c;j++)
		{
			S+=ch;
		}
	}
	long long len=S.length()-1;
	for(int i=0;i<=len/2+1;i++)
	{
		if(S[i]!=S[len-i+1])
		{
			cnt++;
		}
	}
	cout<<cnt;
	return 0;
}
