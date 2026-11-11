#include<bits/stdc++.h>
#define ll long long
using namespace std;
ll n,m,a[200005],ans;

int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin >> n >> m;
	for(int i=1;i<=n;i++)cin >> a[i];
	if(n==m){
		ans=a[1];
		for(int i=2;i<=n;i++)ans&=a[i];
		cout << ans;
		return 0;
	}	
	if(m==1){
		for(int i=1;i<=n;i++)if(a[i]>ans)ans=a[i];
	} 
	if(m==2){
		for(int i=1;i<=n;i++){
			for(int j=i+1;j<=n;j++){
				if((a[i]&a[j])>ans)ans=a[i]&a[j];
			} 
		}
	}
	if(m==n-1){
		int ans1=a[1];
		ans=a[2];
		for(int i=3;i<=n;i++)ans&=a[i];
		for(int i=2;i<=n;i++){
			for(int j=1;j<=n;j++){
				if(j==i)continue;
				ans1&=a[j];
			}
			if(ans1>ans)ans=ans1;
		}
	}
	cout << ans;
	return 0;
}
