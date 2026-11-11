#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
#define fst ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);

const int P=998244353;
const long long INF=0x3f3f3f3f3f3f3f3f;
const int N=1e6+10,M=2e6+10;

long long n;
long long a[N];
char c[N];
long long ans;

int main()
{
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	for(long long i=1;i<=n;i++)
	{
		cin>>a[i]>>c[i];
	}
	long long l=1,r=n;
	long long sl=a[1],sr=a[n];
	char cl=c[1],cr=c[n];
	while(l<r)
	{
		if(sl>sr)
		{
			if(cl!=cr)
			{
				ans+=sr;
			}
			sl-=sr;
			r--;
			sr=a[r];
			cr=c[r];
		}
		else if(sl<sr)
		{
			if(cl!=cr)
			{
				ans+=sl;
			}
			sr-=sl;
			l++;
			sl=a[l];
			cl=c[l];
		}
		else
		{
			if(cl!=cr)
			{
				ans+=sl;
			}
			l++;
			sl=a[l];
			cl=c[l];
			r--;
			sr=a[r];
			cr=c[r];
		}
	}
	cout<<ans;
	return 0;
}

