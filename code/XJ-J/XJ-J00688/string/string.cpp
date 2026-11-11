#include<bits/stdc++.h>
using namespace std;
long long int a[1000005],n,i,j,m,flag,s,p,q=-1,w;
string s1,s2;
char c1[1000005],c[10000005];
int main()
{
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	for(i=0;i<n;i++)
	{
		cin>>a[i]>>c1[i];
		for(p=j;j<a[i]+p;j++)
		c[j]=c1[i];
		m+=a[i];
	}
    w=m;
	m/=2;
	for(i=0,j=w-1;i<m;i++,j--)
		if(c[i]!=c[j])
		    s++;
cout<<s;
	
	
	return 0;
}//3 2 a 2 b 1 c
//2 3 a 2 a
