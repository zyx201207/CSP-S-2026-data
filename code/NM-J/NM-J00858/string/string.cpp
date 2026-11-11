#include<bits/stdc++.h>
using namespace std;
long long n,sum=0;
string b;
int main()
{
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++)
	{
		long long a;
		char c;
		cin>>a>>c;
		for(int i=sum;i<sum+a;i++)
			b=b+c;
	}
	string b1=b.substr(0,b.size()/2),b2=b.substr(b.size()/2);
	int s=b.size();
	string t=b1;
	if(s%2)
		b1=b1+b[s/2+1];
	reverse(t.begin(),t.end());
	b1=b1+t;
	
	if(s%2)
		t=b2.substr(1);
	reverse(t.begin(),t.end());
	b2=t+b2;
	
	int sum1=0,sum2=0;
	for(int i=0;i<s;i++)
	{
		if(b[i]!=b1[i])
			sum1++;
		if(b[i]!=b2[i])
			sum2++;
	}
	cout<<min(sum1,sum2);
	return 0;
 }

