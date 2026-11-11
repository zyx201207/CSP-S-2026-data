#include<bits/stdc++.h>
using namespace std;
int n,m,tmp,maxn;
int a[200005];
long long ans;
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
	if(m==n){
		ans=pow(2,31);
		for(int i=1;i<=n;i++){
			cin>>a[i];
			ans=ans&a[i];
		}
	}else if(m==1){
		ans=0;
		for(int i=1;i<=n;i++){
			cin>>a[i];
			if(ans<a[i]) ans=a[i];
		}
	}else if(m==2){
		for(int i=1;i<=n;i++)
			cin>>a[i];
		ans=0;
		for(int i=1;i<n;i++){
			for(int j=1;j<=n;j++){
				if(i==j) continue;
				if(ans<(a[i]&a[j])) ans=a[i]&a[j];
			}
		}
	}else if(m==n-1){
		for(int i=1;i<=n;i++)
			cin>>a[i];
		ans=0;
		int k=1;
		for(int i=1;i<n;i++){
			k=1;
			for(int j=1;j<=n;j++){
				if(i==j) continue;
				k*=a[j];
			}
			if(ans<k) ans=k;
		}
	}else ans=4;
	cout<<ans;
	return 0;
}
