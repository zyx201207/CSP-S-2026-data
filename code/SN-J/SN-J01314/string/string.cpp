#include<bits/stdc++.h>
using namespace std;
const int N=200015;


int n, a[N], acd[N], c[N], ccd[N];
long long ans=0;

int main()
{
	freopen("string.in", "r", stdin);
	freopen("string.out", "w", stdout);
//	ios::sync_with_stdio(0);
//	cin.tie(0);
	cin>>n;
	long long sl=0;
	for(int i = 1; i<=n; i++)
	{
		char ct;
		cin>>a[i]>>ct;
		c[i]=(int)ct-'a';
		sl+=a[i];
	}
	
	for(int i = 1, j = n; i<=n; i++, j--)
	{
		acd[i]=a[j];
		ccd[i]=c[j];
	}
	long long l=a[1], r=acd[1];
	int ll=1, rr=1;
	
	while(l<sl/2) 
		l+=a[++ll];
	a[ll]-=(l-sl/2);
	a[ll+1]=-1;
	
	while(r<sl/2) r+=acd[++rr];
	acd[rr]-=(r-sl/2);
	acd[rr+1]=-1;
	
//	for(int i = 1; i<=n; i++)
//	{
//		cout<<c[i]<<'|'<<ccd[i]<<endl;
//	}
	
	l=a[1], r=acd[1];
	int lc=c[1], rc=ccd[1];
	ll=1, rr=1;
	while(1)
	{
		
		lc=c[ll];
		rc=ccd[rr];
//		cout<<lc<<';'<<rc<<endl;
		if(l>=r)
		{
			if(lc!=rc)
			{
				ans+=r;
//				cout<<ans<<endl;
			}
			l-=r;
			r=0;
//			cout<<r<<"-a ";
			if(acd[rr+1]!=-1) rr++;
			if(l==r && l==0 && a[ll+1]==-1 && acd[rr+1]==-1) break;
			if(acd[rr]!=-1) r+=acd[rr];
//			cout<<r<<"-a ";
		}
		else if(l<r)
		{
			if(lc!=rc)
			{
				ans+=l;
			}
			r-=l;
			l=0;
//			cout<<l<<"-b ";
			if(a[ll+1]!=-1)  ll++;
			if(a[ll]==-1 && acd[rr+1]==-1) break;
			if(a[ll]!=-1) l+=a[ll];
//			cout<<l<<"-b ";
		}
	}
	cout<<ans;
	return 0;
}



