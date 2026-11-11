#include<bits/stdc++.h>
using namespace std;
string s;
long long ans=0x3f3f3f3f3f3f3f3f;
int main()
{
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	int n,sum=0;
	cin>>n;
	for(int i=1;i<=n;i++)
	{
		long long a;
		char c;
		cin>>a>>c;
		sum+=a;
		for(int i=1;i<=a;i++)
		{
			s+=c;
		 } 
	}
	if(sum%2==1)
	{	
		int l,r;
		l=sum/2;
		r=l;
		//cout<<endl<<l<<endl;
		long long cnt=0;
		while(l>=0&&r<=sum)
		{
			if(s[l]!=s[r])
			{
				cnt++;
			}
			l--;
			r++;
		}
		ans=min(ans,cnt);

	}
	else
	{
		int l,r;
		l=sum/2-1;
		r=l+1;
		//cout<<endl<<l<<endl<<r<<" ((()))";
		long long cnt=0;
		while(l>=0&&r<=sum)
		{
			if(s[l]!=s[r])
			{
				cnt++;
			}
			l--;
			r++;
		}
		ans=min(ans,cnt);
	}
	cout<<ans;
	//cout<<s<<sum;
	return 0;
}
