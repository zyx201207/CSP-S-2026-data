#include<bits/stdc++.h>
using namespace std;

int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	long long n;
	cin>>n;
	string S;
	long long cnt=0;
	string s;
	long long cnt1=0;
	for(int i=0;i<n;i++)
	{
		cin>>cnt;
		cin>>s;
		for(int j=0;j<cnt;j++)
		{
			S+=s;
		}
	}
	
	cnt1=S.size()/2;
	
	long long b=0;
	long long ans=0;
	for(int i=cnt1;i>0;i--)
	{
		if(S[cnt1]!=S[b])
		{
			ans++;
			b++;
			
		}
		else
		{
			b++;
		}
	}
	cout<<ans;
	return 0;
	
}
