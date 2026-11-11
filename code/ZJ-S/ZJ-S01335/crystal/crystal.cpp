#include<bits/stdc++.h>
using namespace std;
long long n,m,a[500005];
long long dis[500005];
long long ans;
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	long long cnt=m,ans1=1;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	sort(a+1,a+n+1);
	dis[1]=0;
	for(int i=2;i<=n;i++){
		dis[i]=a[i]-a[i-1]+dis[i-1];
	}
	long long maxr=n;
	for(int l=1;l<n;l++){
		cnt=m;
		while(dis[maxr]-dis[l]>cnt){
			maxr--;
		}
		for(int i=l+1;i<=maxr;i++){
			if(cnt<=dis[i]-dis[l]){
				if(a[i]==a[i-1]){
					ans1++;
				}
				break;
			}
			ans1++;
			cnt-=dis[i]-dis[l];
		}
		if(ans1>ans){
			ans=ans1;
		}
		ans1=1;
	}
	cout<<ans;
	return 0;
}