#include<bits/stdc++.h>
using namespace std;
#define int long long
const int MAXN=2e5+10;
int n;
int sum,sum2,l,r,s,a[MAXN],f[MAXN],ans,ge;
char c[MAXN];
signed main()
{
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0),cout.tie(0);
	cin>>n;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i]>>c[i];
		sum+=a[i];
		f[i]=f[i-1]+a[i];
	}
	for(int i=1;i<=n;i++)
	{
		sum2+=a[i];
		if(sum2>=sum/2)
		{
			int zf=sum/2,yf=sum/2+sum%2;
			int rst=max(0ll,sum2-yf);
			int lst=max(0ll,zf-f[i-1]);
			//cout<<rst<<' '<<lst<<endl;
			if(rst==lst)
			{
				ge=i-1;
			}
			else if(rst<lst)
			{
				ge=i;
			}
			else
			{
				ge=i-1;
			}
			sum-=a[i]-abs(rst-lst);
			a[i]=abs(rst-lst);
			break;
		}
	}
	r=n;
	l=1;
	//cout<<ge;
	while(l<=ge and r>=ge+1)
	{
		//cout<<l<<' '<<r<<endl;
		if(l==r)
		{
			break;
		}
		if(c[l]!=c[r])ans+=min(a[l],a[r]);
		
		s+=min(a[l],a[r]);
		if(s>=f[l])
		{
			a[r]-=a[l];
			l++;
			
		}
		if(s>=f[n]-f[r-1])
		{
			a[l]-=a[r];
			r--;
		}
		
	}
	cout<<ans;
	return 0;
}
/*
3
2 a
2 b
1 c
*/