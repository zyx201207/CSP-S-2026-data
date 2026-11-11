#include<bits/stdc++.h>
using namespace std;
int n;
char ch[200010];
long long ans=0,sl=0,sr=0,sum=0,bo,a[200010];
string st;
int main()
{
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	
	cin>>n;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i]>>ch[i];
		bo=max(bo,a[i]);
		sum+=a[i];
	}
	if(n==1)//4
	{
		cout<<0<<'\n';
		return 0;
	}
	if(n<=2000&&bo<=50)//40
	{
		for(int i=1;i<=n;i++)
			for(int j=1;j<=a[i];j++)st+=ch[i];
		int len=st.size();
		st=' '+st;
		for(int i=1;i<=len/2;i++)
			if(st[i]!=st[len-i+1])ans++;
		cout<<ans<<'\n';
		return 0;
	}
	int l=1,r=n;
	sum/=2;
	while(l<=r)
	{
		if(l==r)
		{
			
			break;
		}
		if(a[l]>a[r])
		{
			if(ch[l]!=ch[r])ans+=a[r];
			a[l]-=a[r];
			r--;
			continue;
		}
		if(a[l]<a[r])
		{
			if(ch[l]!=ch[r])ans+=a[l];
			a[r]-=a[l];
			l++;
		}
		if(a[l]==a[r])
		{
			if(ch[l]!=ch[r])ans+=a[l];
			l++;r--;
		}
	}
	cout<<ans<<'\n';
	return 0;
}
