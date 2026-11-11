#include<bits/stdc++.h> 
using namespace std;
string w;
int a,n,d,sum,s[200005],f,u=0,p1,p2,ans,l,r;
char c,b[200005];
bool o;
int main()
{
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++)
	{
       	cin>>s[i]>>b[i];
       	d+=s[i];
		//for(int j=1;j<=a;j++)
		//{
			//w+=c;
			//d++;
		//}
	}
	//for(int i=0;i<d/2;i++)
	//{
		//if(w[i]!=w[d-1-i])
		//{
			//sum++;
		//}
	//}
	f=d/2;
	p1=s[1];
	p2=s[n];
	l=1;
	r=n;
	while(l<r)
	{
		if(b[l]!=b[n])
		{
			o=true;
		}
		if(p1>p2)
		{
			u=p2;
			sum+=p2;
			p1-=p2;
			r--;
			p2=s[r];
		}
		else if(p1<p2)
		{
			u=p1;
			sum+=p1;
			p2-=p1;
			l++;
			p1=s[l];
		}
		else
		{
			u=p1;
			sum+=p1;
			l++;
			r--;
			p1=s[l];
			p2=s[r];
		}
		if(o)
		{
			ans+=u;
		}
	}
	cout<<ans;
}
