#include<bits/stdc++.h>
using namespace std;
long long n,m;
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	vector <long long> a(n);
	for(int i=0;i<n;i++) cin>>a[i];
	sort(a.begin(),a.end());
	vector <long long> p(n+1,0);
	for(int i=0;i<n;i++) p[i+1]=p[i]+a[i];
	long long l=0,ans=0;
	for(int r=0;r<n;r++)
	{
		while(l<r)
		{
			long long t=r-l+1;
			long long sum=p[r+1]-p[l];
			long long cnt=t*a[r]-sum;
			if(cnt<=m) 
			{
				break;
			}
			l++;
		}
		ans=max(ans,r-l+1);
	}
	cout<<ans<<endl;
	return 0;            	
}
