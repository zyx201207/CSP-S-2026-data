#include<bits/stdc++.h>
using namespace std;
long long int n,m,a[200005],ans,maxx,x;
int main()
{
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		maxx=max(maxx,a[i]);
		x&=a[i];
	}
	
	ans=a[1];
	if(m==1){
		cout<<maxx;
		return 0;
	}
	if(m==2){
		for(int i=1;i<=n/100;i++){
			for(int j=1;j<=n/100;j++){
				if(i==j)
					continue;
				ans=max(ans,a[j]&a[i]);
			}
		}
		cout<<ans;
		return 0;
	}
	if(m=n)
	{
		cout<<x;
		return 0;
	}
	sort(a+1,a+n+1);
	reverse(a+1,a+n+1);
	for(int i=1;i<=m;i++)
	{
		ans=max(ans,ans&a[i]);
	}
	cout<<ans;
	return 0;
}