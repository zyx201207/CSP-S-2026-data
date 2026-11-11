/*
I AK CSP-J !!!
I AK CSP-J !!!
I AK CSP-J !!!
I AK CSP-J !!!
I AK CSP-J !!!
I AK CSP-J !!!
I AK CSP-J !!!
I AK CSP-J !!!
I AK CSP-J !!!
I AK CSP-J !!!
I AK CSP-J !!!
I AK CSP-J !!!
I AK CSP-J !!!
I AK CSP-J !!!
I AK CSP-J !!!
I AK CSP-J !!!
I AK CSP-J !!!
I AK CSP-J !!!
*/
//#include<bits\stdc++.h>
#include<bits/stdc++.h>
using namespace std;
#define int long long
int n,x,l[200010],r[200010],sum,ans;
char c[200010];
signed main()
{
//	freopen("string.in","r",stdin);
//	freopen("string.out","w",stdout);
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(nullptr),cout.tie(nullptr);
	cin>>n;
	for(int i=1;i<=n;i++)
	{
		cin>>x>>c[i];
		l[i]=sum+1;
		r[i]=sum+x;
		sum+=x;
	}
	int lt=1,rt=sum,ll=1,rr=n;
	while(lt<=rt)
	{
		if(ll==rr)
		{
			break;
		}
		if(l[ll+1]-lt<rt-r[rr-1])
		{
			if(c[ll]!=c[rr])
			{
				ans+=r[ll]-lt+1;
			}
			rt-=l[ll+1]-lt;
			lt+=l[ll+1]-lt;
			ll++;
		}
		else if(l[ll+1]-lt>rt-r[rr-1])
		{
			if(c[ll]!=c[rr])
			{
				ans+=rt-l[rr]+1;
			}
			lt+=rt-r[rr-1];
			rt-=rt-r[rr-1];
			rr--;
		}
		else
		{
			if(c[ll]!=c[rr])
			{
				ans+=r[ll]-lt+1;
			}
			rt-=r[ll]-lt+1;
			lt+=r[ll]-lt+1;
			ll++;
			rr--;
		}
//		cout<<lt<<" "<<rt<<" "<<ll<<" "<<rr<<" "<<ans<<"\n";
	}
	cout<<ans;
	return 0;
}
//start: 8:47
//end: 9:04
/*
wo xiang jin mi huo xing wei da shang
luogu uid=1861592
*/
