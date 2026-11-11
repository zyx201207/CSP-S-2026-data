#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
struct Node{
	ll a,b;
	char c;
};
vector<Node>q;
vector<Node>p;
int main()
{
//	freopen("string.in","r",stdin);
//	freopen("string.out","w",stdout);
	int n,x;
	char ch;
	cin>>n;
	ll len=0;
	for(int i=0;i<n;i++)
	{
		cin>>x>>ch;
		Node y;
		y.a=len;
		y.b=len+x-1;
		y.c=ch;
		q.push_back(y);
		len+=x;
	}
	for(int i=n-1;i>=0;i--)
	{
		Node y;
		y.a=q[i].b;
		y.b=q[i].a;
		y.c=q[i].c;
		p.push_back(y);
	}
	ll l=0,r=0,ql,qr,qql=2e9;
	bool flag=true,f=false,f2=false,f3=false;
	ll sum=0;
	while(flag)
	{
		char a,b;
		a=q[l].c,b=p[r].c;
		ql=q[l].b,qr=p[r].b;
		if(ql>len/2-1)
			ql=len/2-1,f2=true;
		if((1&len)&&qr<len/2+1)
			qr=len/2+1,f=true;
		else if(!(1&len)&&qr<len/2)
			qr=len/2,f=true;
		if(len-ql-1>qr)
		{
			if(!f2)
			{
				f3=true;
				l++;
				//sum+=((int)a!=b)*(len-ql-qr);
				qql=ql;
				continue;	
			}
			else
				qql=ql;
		}
		else
			qql=ql;
		if(a!=b)
		{
			if(len-qql-1>qr)
				sum-=(len-qql-qr);
			sum+=(p[r].a-qr+1);
		}
		r+=(!f);
		if(f&&f2)
			flag=false;
		if(len-ql-1==qr&&(!f2))
			l++,f3=true,qql=ql;
	} 
	printf("%lld",sum);
	return 0;
}

