#include<bits/stdc++.h>
#define int long long
#define endl "\n"
using namespace std;
const int MAXN=5e5+200;
int a[MAXN],b[MAXN],c[MAXN];
int n,m;
signed main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);cout.tie(0);
	cin>>n>>m;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
	}
	sort(a+1,a+n+1);
	/*
	for(int i=1;i<=n;i++)
	{
		cout<<a[i]<<" ";
	}cout<<endl;
	*/ 
	if(n%2)
	{
		for(int i=1;i<=n;i++)
		{
			b[i]=abs(a[i]-a[n/2+1]);
		}
		int cnt=1;
		int l=n/2,r=n/2+2;
		while(m>0&&l>0&&r<=n&&(m>b[l]|m>b[r]))
		{
			if(b[l]<b[r])
			{
				m-=b[l];
				l--;
				cnt++;
			}
			else if(b[l]>=b[r])
			{
				m-=b[r];
				r++;
				cnt++;
			}
		}
		cout<<cnt;
	}
	else if(!(n%2))
	{
		for(int i=1;i<=n;i++)
		{
			b[i]=abs(a[i]-a[n/2]);
			c[i]=abs(a[i]-a[n/2+1]);
		}
		int cnt1=1,cnt2=1;
		int m2=m;
		int l1=n/2-1,r1=n/2+1,l2=n/2,r2=n/2+2;
		while(m>0&&l1>0&&r1<=n&&(m>b[l1]||m>b[r1]))
		{
			if(b[l1]<b[r1])
			{
				//cout<<a[l1]<<" "<<1<<"¡¡";
				m-=b[l1];
				l1--;
				cnt1++;
			}
			else if(b[l1]>=b[r1])
			{
				//cout<<a[r1]<<" "<<2<<" ";
				m-=b[r1];
				r1++;
				cnt1++;
			}
		}
		while(l2>0&&r2<=n&&m2>0&&(m2>c[l2]||m2>c[r2]))
		{
			if(c[l2]<c[r2])
			{
				m2-=c[l2];
				l2--;
				cnt2++;
			}
			else if(c[l2]>=c[r2])
			{
				m2-=c[r2];
				r2++;
				cnt2++;
			}
		}
		//cout<<cnt1<<" "<<cnt2<<endl;
		cout<<max(cnt1,cnt2);
	} 
	return 0;
}
