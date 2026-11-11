#include<bits/stdc++.h>
using namespace std;
const int N=2e5+5;
int n,a[N],temp,p,q,bj,s;
long long ans;
char c[N];
int main()
{
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++)cin>>a[i]>>c[i];
	p=1;q=n;
	while(true)
	{
		
		if(a[p]>a[q])
		{
			temp=a[p]-a[q];
			if(c[p]!=c[q]) ans+=a[q];
			q--;
			a[p]=temp;
		}else
		if(a[p]<a[q])
		{
			temp=a[q]-a[p];
			if(c[p]!=c[q]) ans+=a[p];
			p++;
			a[q]=temp;
		}else
		if(a[p]==a[q])
		{
			if(c[p]!=c[q]) ans+=a[p];
			p++;q--;
		}
		if(p>=q) break;
	}	
	cout<<ans;
	return 0;
}
