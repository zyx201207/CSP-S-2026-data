#include<bits/stdc++.h>
using namespace std;
int a[200010];
int tzw(int x){
	int a=0, t=1;
	while(x){
		int u=x%2; a+=u*t;
		x /= 2; t *= 10;
	}
	return a;
}
int wzt(int x){
	int a=0, t=1;
	while(x){
		int u=x%10; a+=u*t;
		x /= 10; t *= 2;
	}
	return a;
}
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	int n,m; cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	if(m==1){
		int maxx = 0;
		for(int i=1;i<=n;i++){
			maxx = max(maxx,a[i]);
		}
		cout<<maxx;
	}
	else if(m==n){
		int ans = a[1];
		for(int i=2;i<=n;i++){
			ans = wzt(tzw(ans)&tzw(a[i]));
		}
		cout<<ans;
	}
	else if(m==2){
		int maxx = 0;
		for(int i=1;i<n;i++){
			for(int j=i+1;j<=n;j++){
				maxx = max(maxx,wzt(tzw(a[i])&tzw(a[j])));
			}
		}
		cout<<maxx;
	}
	else{
		int maxx=0, ans=a[1];
		for(int i=2;i<=n;i++){
			for(int j=1;j<=n;j++){
				if(j!=i) ans = wzt(tzw(ans)&tzw(a[j]));
			}
			maxx = max(maxx,ans);
		}
		ans = a[2];
		for(int i=2;i<=n;i++){
			ans = wzt(tzw(ans)&tzw(a[i]));
		}
		maxx = max(maxx,ans);
		cout<<maxx;
	}
	return 0;
}