#include<bits/stdc++.h>
using namespace std;
int n,l,r,ans,a[200009];
char c[200009];
bool jj(int e,int d)
{
	int o=a[e]-a[d];
	while(e!=d)
	{
		if(a[d--]<o and c[d--] !=c[e]) 
		{
			o-=a[d--];
			a[d--]=0;
			ans+=a[d--];
		}
		else if(a[d--]<o and c[d--] ==c[e]) 
		{
			o-=a[d--];
			a[d--]=0;
		}
		if(o==0) 
		{
			r=d;
			return 1;
		}
		d--;
	}
	return 0;
}
bool hh(int e,int d)
{
	int o=a[d]-a[e];
	while(e!=d)
	{
		if(a[e++]<o and c[e++]!=c[d]) 
		{
			o-=a[e++];
			a[e++]=0;
			ans+=a[e++];
		}
		
		if(o==0) 
		{
			l=e;
			return 1;
	}
		e++;
	}
	return 0;
}
int main()
{
freopen("string.in","r",stdin);
freopen("string.out","w",stdout);
cin>>n;
for(int i=1;i<=n;i++) cin>>a[i]>>c[i];
r=n;
ans=0;
while(l!=r)
{
	l++;
	if(c[l]!=c[r]) 
	{
		if(a[l]==a[r]) ans+=a[l];
		else if(a[l]>a[r]) 
		{
			if(jj(l,r)) ans+=a[l];
			else 
			{
				ans+=a[l];
				continue;
		}
		}
	    else if(a[r]>a[l]) 
	    {
			if(hh(l,r)) ans+=a[r];
			else 
			{
				ans+=a[r];
				continue;
		}
		}
}
	r--;
}
cout<<ans;
return 0;
}
