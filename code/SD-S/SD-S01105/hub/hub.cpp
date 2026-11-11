#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cmath>
using namespace std;
int n,k;
bool check(int l)
{
	if(l*(k+1)>=n) return true;
	return false;
}
int main(){
	freopen("hub.in","r",stdin);
	freopen("hub.out","w",stdout);
	cin >> n >> k;
	int l=1,r=300000;
	int ans;
	while(l<=r)
	{
		int mid=(l+r)/2;
		if(check(mid))
		{
			ans=r;
			r=mid-1;
		}
		else
		{
			l=mid+1;
		}
	}
	cout << ans;
	return 0;
}

