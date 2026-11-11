#include<bits/stdc++.h>
using namespace std;

struct hui{
	long long num;
	char c;
}a[200050];
int main(){
	
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	int n;
	cin >> n;
	for(int i=1;i<=n;i++) cin >> a[i].num >> a[i].c;
	long long ans=0;
	int l=1 , r=n;
	while(l<r)
	{
		if(a[l].num==a[r].num)
		{
			if(a[l].c!=a[r].c) ans+=a[l].num;
			l++;
			r--;
		}
		else
		{
			if(a[l].c==a[r].c)
			{
				if(a[l].num<a[r].num)
				{
					a[r].num-=a[l].num;
					l++;
				}
				else
				{
					a[l].num-=a[r].num;
					r--;
				}
			}
			else
			{
				if(a[l].num<a[r].num)
				{
					ans+=a[l].num;
					a[r].num-=a[l].num;
					l++;
				}
				else
				{
					ans+=a[r].num;
					a[l].num-=a[r].num;
					r--;
				}
			}
		}
	}
	cout << ans;
	
	return 0; 
}
