#include<bits/stdc++.h>
#define int long long
using namespace std;
int n,m,a[200005];
int maxx1,maxx2;
signed main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	cin>>n>>m;
	bool fA=0;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		for(int k=1;k<=20;k++){
			int y=pow(2,k);
			if(a[i]!=y){
				fA=1;
			}
		} 
		maxx1=max(maxx1,a[i]);
	}
	sort(a+1,a+n+1);
	if(fA==0){
		if((m-1)&2==0){
			cout<<a[n-m+1];
		}
		else{
			cout<<a[n-m+1]+1;
		}
		return 0;
	}
	if(m==1){
		cout<<maxx1;
		return 0;
	}
	if(m==2){
		for(int i=1;i<=n;i++){
			for(int j=i+1;j<=n;j++){
				int x=a[i]&a[j];
				maxx2=max(maxx2,x);
			}
		}
		cout<<maxx2;
		return 0;
	}
	if(m==n){
		int ans=a[1];
		for(int i=2;i<=n;i++){
			ans=ans&a[i];
		}
		cout<<ans;
		return 0;
	}
	cout<<a[(n+1)/2];
	return 0;
}
