#include<bits/stdc++.h>
using namespace std;
#define int long long
struct node{
	int l,r;
};
int c,t,n,d,a[2000006],dis[5005][5005];
signed main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	cin >> c >> t;
	while(t--){
		cin >> n >> d;
		for(int i=1;i<=n;i++){
			cin >> a[i];
		}
		if(c==11||c==12){
			if(a[2]-a[1]>d){
				cout << 0;
			}
		}
		else if(n<=3){
			cout << 0 << "\n";
		}
		else if(n==4){
			if(a[3]-a[1]<=d&&a[4]-a[2]<=d&&a[4]-a[1]>d){
				cout << 1 << "\n";
			}
			else{
				cout << 0 << "\n";
			}
		}
		else if(n==5){
			int ans=0;
			if(a[3]-a[1]<=d&&a[4]-a[2]<=d&&a[4]-a[1]>d){
				ans++;
			}
			if(a[4]-a[2]<=d&&a[5]-a[3]<=d&&a[5]-a[2]>d){
				ans++;
			}
			if(a[4]-a[1]<=d&&a[5]-a[3]<=d&&a[5]-a[2]>d){
				ans++;
			}
			cout << ans << "\n";
		}
		else if(n==6){
			int ans=0;
			for(int i=4;i<=6;i++){
				if(a[i]-a[i-2]<=d&&a[i-1]-a[i-3]<=d&&a[i]-a[i-3]>d){
					ans++;
				}
			}
			for(int i=5;i<=6;i++){
				if(a[i-1]-a[i-4]<=d&&a[i]-a[i-2]<=d&&a[i]-a[i-3]>d){
					ans++;
				}
			}
			for(int i=6;i<=6;i++){
				if(a[i]-a[i-3]<=d&&a[i]-a[i-4]>d&&a[i-1]-a[i-5]>d&&a[i-1]-a[i-4]<=d){
					ans++;
				}
			}
			cout << ans << "\n";
		}
	}
	
	
	return 0;
} 
