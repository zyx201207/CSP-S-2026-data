#include<bits/stdc++.h>
using namespace std;
long long n,a[200005],b[200005],p1=1,p2=1,t=0,p=0,l=0;
char s[200005],c[200005];
int main()
{
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i]>>s[i];
		b[n-i+1]=a[i];
		c[n-i+1]=s[i];
		l+=a[i];
	}
	while(p*2<l){
		int k=min(a[p1],b[p2]);
		a[p1]-=k;
		b[p2]-=k;
		if(s[p1]!=c[p2]){
			t+=k;
		}
		if(a[p1]==0)p1++;
		if(b[p2]==0)p2++;	
		p+=k;
	}
	cout<<t;
	return 0;
}