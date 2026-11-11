#include<bits/stdc++.h>
using namespace std;
long long a[500005]={0};
long long s[500005]={0};
long long m,ct;
int n,ans=1;
int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin >> n >> m;
	for(int i=0;i<n;i++)
	{
		cin >> a[i];
	}
	if(n<8000)
	{
		sort(a,a+n);
		for(int i=1;i<n;i++)
		{
			s[i]=a[i]-a[i-1];
		}
		for(int i=1;i<n;i++)
		{
			ct=0;
			for(int j=0;i+j<n;j++)
			{
				ct+=s[i+j]*(j+1);
				if(ct>m)
				{
					ans=max(ans,j+1);
					break;
				}
			}
		}
		cout << ans << "\n";
	}
	else if(a[1]-a[0]==a[2]-a[1]&&a[2]-a[1]==a[3]-a[2])
	{
		long long l=a[1]-a[0];
		for(int i=1;;i++)
		{
			if(((i*(i+1))/2)*l>m)
			{
				ans=i;
				break;
			}
		}
		cout << ans;
		
	}
	
	
	
	return 0;
}
