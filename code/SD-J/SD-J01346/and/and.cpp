#include<bits/stdc++.h>
using namespace std;
const int N=2e5;
long long n,m,a[N];
bool f[N];
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0),cout.tie(0);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i]; 
	}
	if(m==n){
		long long ans=1;
		for(int i=1;i<=n;i++){
			ans=ans&a[i];
		}
		cout<<ans;
		return 0;
	}else if(m==2){
		long long ans=-1;
		for(int i=1;i<=n;i++){
			for(int j=1;j<=n;j++){
				if(i!=j){
					ans=max(ans,a[i]&a[j]);
				}
			}
		}
		cout<<ans;
		return 0;
	}else if(m==1){
		sort(a,a+1+n);
		cout<<a[n];
		return 0;
	}else{
		for(int i=1;i<=n;i++){
			long long ans=a[i],cnt=0;
			for(int j=1;j<=n&&j!=i;j++){
				if(ans&a[j]>ans){
					ans=ans&a[j];
					cnt++;
					f[j]=1;
				}
			}
			long long ans2=1e9;
			while(cnt<m){
				cnt++;
				for(int k=1;k<=n;k++){
					if(f[i]==0){
						ans2=min(ans2,ans&a[k]);
					}
				}
			}
		}
		cout<<ans2; 
	}
	return 0;
}
