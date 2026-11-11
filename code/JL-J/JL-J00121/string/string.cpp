#include<bits/stdc++.h>
using namespace std;
long long a[200010];
char c[200010];
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	long long n,len=0,cnt=0;
	string s1,s2,s3;
	cin>>n;
	for(int i=0;i<n;i++)
		cin>>a[i]>>c[i];
	for(int i=0;i<n;i++)
	{
		for(int j=0;j<a[i];j++)
		{
			s1.push_back(c[i]);
		}
	}
	len=s1.size();
	if(len%2==0) 
	{
		for(int i=0;i<len/2;i++)
		{
			s2.push_back(s1[i]);
			s3.push_back(s1[i]);
		}
	}
	else if(len%2!=0) 
	{
		for(int i=0;i<(len-1)/2;i++)
			s2.push_back(s1[i]);
		for(int i=0;i<(len+1)/2;i++)
			s3.push_back(s1[i]);
	}
	reverse(s2.begin(),s2.end());
	for(size_t i=0;i<s2.size();i++)
	{
		s3.push_back(s2[i]);
	}
	for(int i=len/2;i<len;i++)
	{
		if(s1[i]!=s3[i]) cnt++;
	}
	cout<<cnt<<endl;
	return 0;
}
