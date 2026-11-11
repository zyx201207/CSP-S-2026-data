#include<bits/stdc++.h>
using namespace std;
long long n,m;
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	long long a[n];
	if(n==1){
		cout<<1;
	}else if(n<=5000){
		for(int i=1;i<=n;i++){
			cin>>a[i];
		}
		int mx=-1;
		for(int i=2;i<=n;i++){
			int ans=1,mm=m;
			for(int j=i-1;j>=1;j--){
				if(mm>=(a[i]-a[j])){
					mm-=(a[i]-a[j]);
					ans++;
				}
			}
			mx=max(mx,ans);
		}
		cout<<mx;	
	}else{
		for(int i=1;i<=n;i++){
			cin>>a[i];
		}
		sort(a+1,a+1+n);
		int ans=1,j=0;
		for(int i=1;i<=n;i++){
			if(j+a[i]<=m){
				j+=a[i];
				ans++;
			}
			else {
				cout<<ans;
				break;
			}
		}		
	}
	return 0;
} 
