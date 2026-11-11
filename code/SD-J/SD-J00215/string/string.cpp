#include<iostream>
using namespace std;
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	string m,l,b;
	long long n,a,c=0;
	cin>>n;
	for(long long i=0;i<n;i++)
	{
		cin>>a>>b;
		for(long long j=0;j<a;j++)
		{
		    m+=b;
		}
	}
	for(long long i=m.size()-1;i>=0;i--)
	{
		l+=m[i];
	}
	for(long long k=0;k<m.size()/2;k++)
	{
		if(m[k]!=l[k])
		{
			c++; 
		}
	}
	cout<<c;
	return 0;
}
