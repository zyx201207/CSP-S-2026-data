//#include<bits\stdc++.h>
//freopen("crystal.in","r",stdin);
//freopen("crystal.out","w",stdout);
//freopen("crystal.ans","w",stdout);
#include<bits/stdc++.h>
#define int long long
using namespace std;
int n,m;
int a[1000005];
int sum;
int maxx;
signed main(){
	ios::sync_with_stdio(0),cin.tie(0);
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	bool f=1,f1=1;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		if(a[i]!=i){
			f=0;
		}
		sum+=a[i];
	}
	int g=a[2]-a[1];
	for(int i=2;i<=n;i++){
		if(a[i]-a[i-1]!=g){
			f1=0;
		}
	}
	sort(a+1,a+1+n);
	if(n<=5000){
		for(int i=1;i<=n;i++){
			int ans=0;
			int k=m;
			for(int j=i;j>=1;j--){
				if(a[i]-a[j]<=k){
					ans++;
					k-=a[i]-a[j];
				}
				maxx=max(maxx,ans);
			}
		}
		cout<<maxx;
		return 0;
	}
	if(f==1||f1==1){
		if(n%2==0){
			int k=m;
			int ans=0;
			for(int l=n;l>=1;l--){
				if(a[n]-a[l]<=k){
					ans++;
					k-=a[n]-a[l];
				}
				maxx=max(maxx,ans);
			}
		}
		cout<<maxx;
		return 0;
	}
//	int mid=(n+1)/2;
//	int ans=1;
//	int k=m;
	int ans=0;
	for(int i=1;i<=n;i++){
		if(a[i]==a[i+1]){
			ans++;
		}
		maxx=max(ans,maxx);
	}
	cout<<maxx;
	return 0;
}  
