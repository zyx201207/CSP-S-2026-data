#include<bits/stdc++.h>
using namespace std;
long long n,m,a[500005],flag1,flag2,A,s[500005];
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	sort(a+1,a+n+1);
	if(n<=50000){
		int ans,mx=-1;
		for(int i=n;i>=1;i--){
			long long x=m,j=i-1;
			ans=0;
			while(x>=0&&j>=0){
				x=x-a[i]+a[j];
				j--;
				ans++;
			}
			mx=max(mx,ans);
			if(i<=mx) break;
		}
		cout<<mx;
		return 0;
	}
	A=abs(a[2]-a[1]);
	for(int i=2;i<=n;i++){
		if(abs(a[i]-a[i-1])!=A) flag2=1;
	}
	if(!flag2||!flag2){
		for(int i=n;i>=1;i--){
			if((a[i-1]+a[1])*i/2<=m){
				cout<<i;
				return 0;
			}
		}
	}
	long long ans,mx=-1;
	long long x=m,j=n-1;
	ans=0;
	while(x>=0&&j>=0){
		x=x-a[n]+a[j];
		j--;
		ans++;
	}
	mx=max(mx,ans);
	for(int i=n;i>=1;i--){
		ans--;
		x+=ans*(a[i]-a[i-1]);
		while(x>=0&&j>=0){
			x=x-a[i-1]+a[j]; 
			j--;
			ans++;
		}
		mx=max(mx,ans);
	}
	cout<<mx;
	return 0;
}
