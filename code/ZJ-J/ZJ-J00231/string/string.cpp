#include<bits/stdc++.h>
using namespace std;
int main()
{
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	int n,a[200005];
	long long L = 0,sum = 0;
	long long l=0,r,ll = 0,rr;
	char b[200005];
	cin>>n;
	r = n;
	for(int i = 1;i <= n;i++)
	{
		cin>>a[i]>>b[i];
		L+=a[i];
	}
	rr = L;
	while(ll<=rr)
	{
		if(ll>L-rr+1)
		{
			r--;
			rr-=a[r];
			if(b[l]!=b[r])
			{
				if(L-rr>=ll)
				{
					sum += L-rr+1-ll;
				}
				else{
					sum+=ll-L+rr-1;
				}
			}
		}
		else{
			l++;
			ll+=a[l];
			if(b[l]!=b[r])
			{
				if(L-ll>=rr)
				{
					sum += L-ll+1-rr;
				}
				else{
					sum+=rr-L+ll-1;
				}
			}
		}
	}
	cout<<sum;
}