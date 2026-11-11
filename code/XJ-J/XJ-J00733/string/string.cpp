#include<bits/stdc++.h>
using namespace std;
long long a[200005]={0};
char s[200005]={0};
int main()
{
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	int n;
	cin>>n;
	long long l=0;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i]>>s[i];
		l=l+a[i];
	}
	long long diff=0;
//	cout<<l<<endl;
	for(int i=1,j=l;;i++,j--)
	{
		if(i>=j) break;
		long long i1=i,j1=l-j;
		char q,h;
		long long k;
		for(k=1;i1>a[k];k++)
		{
			if(i1>a[k]) i1-=a[k];
			else break;
		}
		q=char(s[k]);
		for(k=n;j1>a[k];k--)
		{
			if(j1>a[k]) j1-=a[k];
			else if(j1<=a[k]) break;
//			cout<<"// "<<k<<endl;
		}
		h=char(s[k]);
		if(q!=h) diff++;
//		cout<<q<<" "<<h<<" : "<<diff<<endl;
//		cout<<"  "<<i<<" "<<j<<endl;
	}
	cout<<diff;
	return 0;
}

