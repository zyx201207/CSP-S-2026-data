#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N=2e5+10;
int n,sum=0,a[N];
char c[N];
signed main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0),cout.tie(0);
	cin>>n;
	for(int i=1;i<=n;++i)
	{
		cin>>a[i]>>c[i];
		sum+=a[i];
	}
	int l1=1,r1=n;
	n=sum;
	int q=0,l=1,r=n;
	while(l1<r1)
	{
		if(a[l1]==a[r1])
		{
			if(c[l1]!=c[r1])
			{
				q+=a[l1];
			}
			l+=a[l1];
			r-=a[r1];
			l1++;
			r1--;
		}
		else if(a[l1]>a[r1])
		{
			if(c[l1]!=c[r1])
			{
				q+=a[r1];
			}
			a[l1]-=a[r1];
			l+=a[r1];
			r-=a[r1];
			r1--;
		}
		else
		{
			
			if(c[l1]!=c[r1])
			{
				q+=a[l1];
			}
			a[r1]-=a[l1];
			l+=a[l1];
			r-=a[l1];
			l1++;
		}
	}
	cout<<q;
	return 0;
}

