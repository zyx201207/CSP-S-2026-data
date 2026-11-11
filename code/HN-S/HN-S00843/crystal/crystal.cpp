#include<bits/stdc++.h>
#define ll long long
using namespace std;
const int N=500010;
int n,ans;
ll m,mx=LLONG_MIN,mn=LLONG_MAX;
ll a[N];
bool f1,f2;
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	f1=f2=1;
	int c=-1;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		if(a[i]!=i) f1=0;
		if(c==-1&&i>1) c=a[i]-a[i-1];
		else if(a[i]-a[i-1]!=c) f2=0;
		mx=max(mx,a[i]);
		mn=min(mn,a[i]);
	}
	if(n<=5000){
		sort(a+1,a+n+1);
		for(int i=1;i<=n;i++){
			ll sum=0;
			bool f=1;
			for(int j=i;j>=1;j--){
				if(sum+a[i]-a[j]>m){
					ans=max(ans,i-j);
					f=0;
					break;
				}
				sum+=(a[i]-a[j]);
			}
			if(f) ans=max(ans,i);
		}
		cout<<ans;
	}
	else if(f1){
		ll sum=0;
		ans=1;
		for(int i=1;i<n;i++){
			if(sum+i>m) break;
			ans++;
			sum+=i;
		}
		cout<<ans;
	}
	else if(f2){
		ll sum=0;
		ans=1;
		for(int i=1;i<n;i++){
			if(sum+i*c>m) break;
			ans++;
			sum+=i*c;
		}
		cout<<ans;
	}
	else if(mx<=100){
		int tmp[N];
		sort(a+1,a+n+1);
		for(int i=mn;i<=mx;i++){
			ll sum=0;
			int cnt=0,len=0;
			for(int j=1;j<=n;j++){
				if(a[j]-i>0) break;
				tmp[j]=i-a[j];
				len++;
			}
			for(int j=len;j>0;j--){
				if(sum+tmp[j]>m) break;
				sum+=tmp[j];
				cnt++;
			}
			ans=max(ans,cnt);
		}
		cout<<ans;
	}
	return 0;
}
