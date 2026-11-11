#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N=5e5+5;
int n,m,a[N],d[N],s[N],ans=1;
bool b1=1,b2=1;
signed main()
{
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	sort(a+1,a+1+n);
	int c=a[2]-a[1];
	for(int i=1;i<=n;i++){
		s[i]=s[i-1]+a[i];
		d[i]=a[i]-a[i-1];
		if(d[i]!=1) b1=0;
		if(d[i]!=c) b2=0;
	}
	if(m==0||n==1){
		cout<<1;
		return 0;
	}
	else if(b1==1){
		for(int i=1;i<=n;i++){
			if((i*(i+1))/2<=m) ans++;
		}
		cout<<ans;
	}
	else if(b2){
		for(int i=1;i<=n;i++){
			if((i*(i+1))/2*c<=m) ans++;
		}
		cout<<ans;
	}
	else{
		for(int i=n;i>=1;i--)
	{
		int ans1=1,m1=m;
		for(int j=i-1;j>=1;j--){
			if(a[i]-a[j]<=m1){
				ans1++;
				m1-=a[i]-a[j];
			}
			else break;
		}
		ans=max(ans,ans1);
	}
	cout<<ans;
	}
	return 0;
	fclose(stdin);
	fclose(stdout);
}
