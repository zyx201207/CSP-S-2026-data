#include<bits/stdc++.h>
using namespace std;

int n;
long long len=0;
long long a[200005];
char c[200005];

struct seg
{
	long long l;
	char c;
}lft[200005],rgt[200005],rgt2[500001];

int posl=0,posr=0,posr2=0;

int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0),cout.tie(0);
	cin>>n;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i]>>c[i];
		len+=a[i];
	}
	long long ll=0;
	for(int i=1;i<=n;i++)
	{
		ll+=a[i];
		if(ll<=len/2)
		{
			lft[++posl]={a[i],c[i]};
		}
		else
		{
			if(ll-a[i]+1<=len/2)
			{
				long long res=len/2-(ll-a[i]+1)+1;
				lft[++posl]={res,c[i]};
				if(a[i]-res-(len%2==1)>0)
				{
					rgt[++posr]={a[i]-res-(len%2==1),c[i]};
				}
			}
			else
			{
				if(len%2==1&&ll-a[i]+1==len/2+1)
				{
					a[i]--;
				}
				rgt[++posr]={a[i],c[i]};
			}
		}
	}
	reverse(rgt+1,rgt+posr+1);
	long long l=0,r=0;
	long long L=0,R=0,idxr=1;
	for(int i=1;i<=posl;i++)
	{
		l=r+1;
		r+=lft[i].l;
		while(idxr<=posr&&R+rgt[idxr].l<=r)
		{
			L=R+1;
			R+=rgt[idxr].l;
			rgt2[++posr2]={R-L+1,rgt[idxr].c};
			idxr++;
		}
		if(idxr<=posr&&R+rgt[idxr].l>r)
		{
			L=R+1;
			R+=rgt[idxr].l;
			rgt2[++posr2]={r-L+1,rgt[idxr].c};
			while(i+1<=posl&&r+lft[i+1].l<=R)
			{
				i++;
				l=r+1;
				r+=lft[i].l;
				rgt2[++posr2]={r-l+1,rgt[idxr].c};
			}
			if(R>r)
			{
				rgt2[++posr2]={R-r,rgt[idxr].c};
			}
			idxr++;
		}
	}
	l=0,r=0;
	L=0,R=0;
	idxr=1;
	long long ans=0;
	for(int i=1;i<=posl;i++)
	{
		l=r+1;
		r+=lft[i].l;
		while(idxr<=posr2&&R+rgt2[idxr].l<=r)
		{
			L=R+1;
			R+=rgt2[idxr].l;
			if(rgt2[idxr].c!=lft[i].c)
			{
				ans+=(R-L+1);
			}
			idxr++;
		}
	}
	cout<<ans;
	return 0;
}
/*
3
1 a
2 b
2 c
*/
