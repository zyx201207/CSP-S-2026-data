#include <bits/stdc++.h>
using namespace std;
long long a[500005];
long long d[500005];
int main()
{
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	//cout<<sizeof(a)/1024/1024;
	int n;
	long long m;
	cin>>n>>m;
	for(int i = 1;i<=n;i++) cin>>a[i];
	sort(a+1,a+n+1);
	long long tp = a[2]-a[1];
	int flag = 1;
	for(int i = 2;i<=n;i++) if(a[i]-a[i-1]!=tp) flag = 0;
	if(flag == 1) 
	{
		long long anstp = 1;
		sort(a+1,a+n+1);
		for(int i = 1;i<n;i++){
			if(m>=tp*i) 
			{
				m-=tp*i;
				anstp++;
			}
		}
		cout<<anstp;
		return 0;
	}
	//for(int i = 1;i<=n;i++) cout<<a[i]<<endl;
	long long ans = 0;
	for(int i = 1;i<=n;i++)
	{
		for(int s = 1;s<=n;s++) d[s] = a[s];
		long long t = m;
		for(int j = 1;j<=i;j++)
		{
			if(t<=0||t<a[i]-d[j]){
				j = i;
				continue;
				//cout<<"continue"<<j<<endl;
			}
			t = t-a[i]+d[j];
			d[j] = a[i];
		}
		long long ansl = 0;
		for(int j = 1;j<=i;j++) if(d[j]==a[i]) ansl++;
		ans = max(ansl,ans);
	} 
	cout<<ans;
	return 0;
}
