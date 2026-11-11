#include<bits/stdc++.h>
using namespace std;
int n;
long long A[200005],s,wz,ans;
char C[200005];
struct node{long long a;char c;};
vector<node> l,r;
int main()
{
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++)
	{
		cin>>A[i]>>C[i];
		s+=A[i];
	}
	if(s%2==0)
	{
		s/=2;
		for(int i=1;i<=n;i++)
		{
			if(wz>s)
			{
				r.push_back({A[i],C[i]});
				continue;
			}
			wz+=A[i];
			if(wz<=s)
			  l.push_back({A[i],C[i]});else
			  {
			  	  l.push_back({A[i]-(wz-s),C[i]});
			      r.push_back({wz-s,C[i]});
			  }
		}	
	}else
	{
		s=s/2;
		for(int i=1;i<=n;i++)
		{
			if(wz>s)
			{
				r.push_back({A[i],C[i]});
				continue;
			}
			wz+=A[i];
			if(wz<=s)
			  l.push_back({A[i],C[i]});else
			  {
			  	  l.push_back({A[i]-(wz-s),C[i]});
			      r.push_back({wz-s-1,C[i]});
			  }
		}	
	}
	int L=0,R=r.size()-1;
	while(L<l.size()&&R>=0)
	{
		node z=l[L];
		node y=r[R];
		long long mn=min(z.a,y.a);
		if(l[L].c==r[R].c)
		{
			r[R].a-=mn;
			l[L].a-=mn;
		}else
		{
			ans+=mn;
			r[R].a-=mn;
			l[L].a-=mn;
		}
		if(r[R].a==0)
		  R--;
		if(l[L].a==0)
		  L++;
	}
	cout<<ans;
	return 0;
}