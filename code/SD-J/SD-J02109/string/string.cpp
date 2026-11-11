#include<bits/stdc++.h>
#define endl '\n'
//#define int long long
using namespace std;
const int N=1e6+10;

int n,a[N],ans,cnt;
string s;
char c;
int main()
{
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0),cout.tie(0);
	cin>>n;
	for(int i=1;i<=n;++i)
	{
		cin>>a[i];
		cin>>c;
		for(int j=1;j<=a[i];++j)
		{
			s+=c;
		}
	}
	int len=s.size();
	if(len%2==0)
	{
		for(int i=1,j=len;i<=len/2&&j>=len/2;++i)
		{
			if(s[i]!=s[j])
			{
				ans++;
			}
		}
	}
	if(len%2==1)
	{
		for(int i=0,j=len-1;i<=len-1&&j>=0;i++,j--)
		{
			
			if(s[i]!=s[j])
			{
				s[i]=s[j];
				ans++;
			}
		}
	}
	cout<<ans;
	return 0;
}

