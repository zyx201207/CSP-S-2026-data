//袁骏逸 SN-J00837 西安市铁一中学 
#include<bits/stdc++.h>
using namespace std;
#define int long long

int n;
int sum,idx;
int a[200005];
char b[200005];
bool f[200005],ff[200005];
struct node{
	int num;
	char c;
}A[200005];
int maxn;
void solve()
{
	string s;
	for(int i=1;i<=n;i++)
	{
		for(int j=1;j<=a[i];j++)
		{
			s+=b[i];
		}
	}
	int ans=0;
	for(int i=0,j=s.size()-1;i<=j;i++,j--)
	{
		if(s[i]!=s[j])ans++;
	}
	cout<<ans;
}
signed main()
{
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	scanf("%lld",&n);
	for(int i=1;i<=n;i++)
	{
		scanf("%lld%s",&a[i],&b[i]);
		maxn=max(maxn,a[i]);
		sum+=a[i];
	}
	if(maxn<=50)
	{
		solve();
		exit(0);
	}
	char last=b[1];
	int tot=a[1];
	for(int i=2;i<=n;i++)
	{
		if(b[i]==last)
		{
			tot+=a[i];
		}
		else 
		{
			A[++idx]=node{tot,b[i-1]};
			tot=a[i];
		}
		last=b[i];
	}
	A[++idx]=node{tot,b[n]};
	
	
		tot=0;
		for(int i=1;i<=idx;i++)
		{
			tot+=A[i].num;
			if(tot==sum/2)
			{
				break;
			}
			else if(tot>sum/2)
			{
				int r=tot-sum/2;
				int l=A[i].num-r;
				char ch=A[i].c;
				A[i]=node{l,ch};
				for(int j=idx;j>=i+1;j--)
				{
					A[j+1].num=A[j].num;
					A[j+1].c=A[j].c;
				}
				A[i+1]=node{r,ch};
				idx++;
				break;
				
			}
		}
		int l=1,r=idx,ans=0,pos=0;
		while(l<=r)
		{
			
			char ch=A[l].c; 
			pos+=A[r].num;
			//cout<<l<<" "<<r<<" "<<pos<<" "<<ans<<endl;
			 
			if(pos>=A[l].num)
			{
				int x=A[r].num-(pos-A[l].num);
				if(A[r].c!=A[l].c)ans+=x;
				//cout<<x<<endl;
				l++;
				A[r].num-=x;
				pos=0;
			}
			else 
			{
				if(A[r].c!=A[l].c)ans+=A[r].num;
				r--;
				
			}
		}
		cout<<ans;
	

	
	return 0;
}
