#include<bits/stdc++.h>
using namespace std;
int main()
{
freopen("string.in","r",stdin);
freopen("string.out","w",stdout);
string b;
long long n,a,sum=0;
cin>>n;
for(int i=1;i<=n;i++)
{
	cin>>a;
	for(int j=1;j<a;j++)
	{	
	getline(cin,b);
    }  
reverse(b.begin(),b.end());
if(b.begin()!=b.end())
sum++;
}
cout<<sum-1;
return 0;
}
 
