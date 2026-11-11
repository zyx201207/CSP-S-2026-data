#include <bits/stdc++.h>
using namespace std;
long long m,chec,x=0;
int n,ans=1,startn=1;
long long a[500005];
int main()
{
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	int ans1=1;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	
	sort(a+1,a+1+n);
	for(int i=1;i<=n;i++){
		chec=(a[i+1]-a[i])*ans;
		x+=chec;
		//cout<<x<<endl;
		if(x<=m)ans++;
		while(x>m){
			x-=a[i]-a[startn];
			ans--;
			
		}
		
		ans1=max(ans1,ans);
	}
	cout<<ans1;
	return 0;
}