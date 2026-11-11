#include<bits/stdc++.h>
using namespace std;
int n;
long long a[300000];
string s,s1;
char b;

int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin >>n;
	long long d=0;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
		d+=a[i];
		cin >>b;
		for(int j=1;j<=a[i];j++)
		{
			s+=b;
			s1+=b;
		}
	}
	reverse(s.begin(),s.end());
	long long sum=0;
	for(int i=0;i<d;i++)
	{
		if(s1[i]!=s[i])
		{
			sum++;
		}
	}
	
	cout <<sum/2;
return 0;	
}