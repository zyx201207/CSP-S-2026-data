#include<bits/stdc++.h> 
using namespace std;
int n;
long long m,a[500005],k,ans=1,ans1,c[500005],maxx=-1,minn=0x3f3f3f3f3f;
bool cmp(int x,int y){
	return x>y;
}
int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++)cin>>a[i];
	sort(a+1,a+n+1,cmp);
	c[1]=a[1];
	for(int i=2;i<=n;i++){
		c[i]=a[i-1]-a[i];
		maxx=max(maxx,c[i]);
		minn=min(minn,c[i]); 
	} 
	if(maxx==minn){
		ans=1;
		k=m;
		for(int j=2;j<=n;j++){
			if(a[1]-a[j]>k)break;
			else{
				k-=(a[1]-a[j]);
				ans++;
			} 		
		}
		cout<<ans;
		return 0;
	}
	for(int i=1;i<=n;i++){
		ans=1;
		k=m;
		for(int j=i+1;j<=n;j++){
			if(a[i]-a[j]>k)break;
			else{
				k-=(a[i]-a[j]);
				ans++;
			} 		
		}
		ans1=max(ans1,ans);
	}
	cout<<ans1;
	return 0;	
}
