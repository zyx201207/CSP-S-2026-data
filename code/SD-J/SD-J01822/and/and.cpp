# include<bits/stdc++.h>
using namespace std;
const int N=2e5+5;
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	int n,m,a[N];
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	if(m==1){
		int maxx=0;
		for(int i=1;i<=n;i++){
			maxx=max(maxx,a[i]);
		}
		cout<<maxx;
	}else if(m==2){
		int ans=0;
		for(int i=1;i<n;i++){
			for(int j=i+1;j<=n;j++){
				int t=a[i]&a[j];
				ans=max(ans,t);
			}
		}
		cout<<ans;
	}else if(m==n){
		int ans=a[1];
		for(int i=2;i<=n;i++){
			ans&=a[i];
		}
		cout<<ans;
	}else if(m==n-1){
		int ans=0;
		for(int i=1;i<=n;i++){
			int maxx=a[1];
			if(i==1) maxx=a[2];
			for(int j=1;j<=n;j++){
				if(j!=i){
					ans&=a[j];
				}
			}
			ans=max(maxx,ans);
		}
		cout<<ans;
	}
	return 0;
}
