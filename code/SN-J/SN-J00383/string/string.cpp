#include<bits/stdc++.h>
#define int long long
using namespace std;
int n;
const int N=2e5+5;
int a[N],cnt,sum[N];
char s[N];
signed main()
{
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
//	system("fc myT2.out string6.ans");
	ios::sync_with_stdio(false),cin.tie(0),cout.tie(0);
	cin>>n;
	for(int i=1;i<=n;i++)cin>>a[i]>>s[i];
	for(int i=1;i<=n;i++)
	{
		cnt+=a[i];
		sum[i]=cnt;
	}
//	cout<<cnt<<'\n'; 
	if(cnt%2==1)
	{
		int mid=0,dd=cnt/2+1,uu=0;
		for(int i=1;i<=n;i++)
		{
			uu+=a[i];
			if(uu>=dd)
			{
				mid=i;
				break;
			}
		}
		int l=mid,r=mid,lsheng=dd-sum[mid-1]-1,rsheng=sum[mid]-dd,ans=0;
		while(l>=1&&r<=n)
		{
//			cout<<l<<' '<<r<<' '<<lsheng<<' '<<rsheng<<'\n';
			if(l<1)break;
			if(r>n)break;
			if(lsheng>rsheng)
			{
				lsheng-=rsheng;
				if(s[l]!=s[r])ans+=rsheng;
				r++;
				rsheng=a[r];
			}
			else if(lsheng<rsheng)
			{
				rsheng-=lsheng;
				if(s[l]!=s[r])ans+=lsheng;
				l--;
				lsheng=a[l];
			}
			else if(lsheng==rsheng)
			{
				if(s[l]!=s[r])ans+=lsheng;
				l--,r++;
				lsheng=a[l],rsheng=a[r];
			}
		}
		cout<<ans;
	}
	else if(cnt%2==0)
	{
		int mid=0,dd=cnt/2,uu=0,ans=0;
		bool flag=0;
		for(int i=1;i<=n;i++)
		{
			uu+=a[i];
			if(uu>=dd&&uu-dd>=1)
			{
				flag=1;
				mid=i;
				break;
			}
			else if(uu==dd)
			{
				mid=i;
				break;
			}
		}
		int l=mid,r=mid,lsheng=dd-sum[mid-1]-1,rsheng=sum[mid]-dd-1;
		if(!flag)
		{
			rsheng=sum[mid+1]-dd-1;
			r=mid+1;
			ans=1;
		}
		while(l>=1&&r<=n)
		{
//			cout<<l<<' '<<r<<' '<<lsheng<<' '<<rsheng<<'\n';
			if(l<1)break;
			if(r>n)break;
			if(lsheng>rsheng)
			{
				lsheng-=rsheng;
				if(s[l]!=s[r])ans+=rsheng;
				r++;
				rsheng=a[r];
			}
			else if(lsheng<rsheng)
			{
				rsheng-=lsheng;
				if(s[l]!=s[r])ans+=lsheng;
				l--;
				lsheng=a[l];
			}
			else if(lsheng==rsheng)
			{
				if(s[l]!=s[r])ans+=lsheng;
				l--,r++;
				lsheng=a[l],rsheng=a[r];
			}
		}
		cout<<ans;
	}
	return 0;
}
//CSP-J RP++ 
