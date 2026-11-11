#include <bits/stdc++.h>
using namespace std;
int n,m,a[200005];
int e[2005][40];
int t[40];
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
	int ml=0;
	for(int i=1;i<=n;i++){
		int l=0;
		cin>>a[i];
		int x=a[i];
		while(x){
			e[i][++l]=x%2;
			x/=2;
			t[l]+=e[i][l];
		}
		ml=max(ml,l);
	}
	if(m==1){
		sort(a+1,a+n+1);
		cout<<a[n];
	}
	else if(m==2){
		int mx=0;
		for(int i=1;i<=n;i++){
			for(int j=i;j<=n;j++){
				if(i==j){
					continue;
				}
				mx=max(mx,(a[i]&a[j]));
			}
		}
		cout<<mx;
	}
	else if(m==n){
		int ans=0;
		for(int i=1;i<=ml;i++){
			if(t[i]==0 || t[i]==m){
				ans+=pow(2,i-1);
			}
		}
		cout<<ans;
	}
	else if(m==n-1){
	 	int mx=0;
	 	for(int i=1;i<=n;i++){
	 		for(int j=1;j<=n;j++){
				if(j==i){
					continue;
				}
				int ans=0;
				for(int k=1;k<=ml;k++){
					if(t[k]==0 || t[k]==m){
						ans+=pow(2,i-1);
					}
				}
				mx=max(ans,mx);
			}
		}
		cout<<mx;
	}
	else{
		sort(a+1,a+n+1);
		cout<<a[n-m+1];
	}
	return 0;
}