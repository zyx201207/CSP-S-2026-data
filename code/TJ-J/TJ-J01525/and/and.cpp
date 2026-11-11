#include <bits/stdc++.h> 

using namespace std;
long long dp[200005];
long long a[200005];
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(nullptr);
	cout.tie(nullptr);
	int n,m;
	cin>>n>>m;
	long long maxx=0;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	if(m==1){
		for(int i=1;i<=n;i++){
			maxx=max(maxx,a[i]);
		}
		cout<<maxx;
		return 0;
	}
	if(m==2){
		for(int i=1;i<=n;i++){
			for(int j=1;j<=n;j++){
				if(i!=j){
					maxx=max(maxx,a[i]&a[j]);
				}
			}
		}
		cout<<maxx<<endl;
		return 0;
	}
	if(m==n){
		maxx=a[1];
		for(int i=2;i<=n;i++){
			maxx&=a[i];
		}
		cout<<maxx;
		return 0;
	}
	/*if(m==n-1){
		maxx=a[1];
		for(int i=2;i<=n;i++){
			maxx^=a[i];
		}
		
	}*/
	sort(a+1,a+n+1);
	maxx=(1<<25)-1;
	for(int i=n;i>=n-m+1;i--){
		maxx&=a[i];
	}
	cout<<maxx;
	return 0;
}
