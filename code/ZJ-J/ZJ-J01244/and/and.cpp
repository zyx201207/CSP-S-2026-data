#include<bits/stdc++.h>
using namespace std;
long long n,m,ans;
long long a[200010];
long long b[200010];
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin >> n >> m;
	for(int i=1;i<=n;i++){
		cin >> a[i];
		b[i]=a[i];
	}
	for(int i=30;i>=0;i--){
		int cnt=0;
		for(int j=1;j<=n;j++){
			if(b[j]-pow(2,i)>=0){
				b[j]-=pow(2,i);
				cnt++;
			}
		}
		if(cnt<m){
			for(int j=1;j<=n;j++){
				if(a[j]-pow(2,i)>=0){
					a[j]-=pow(2,i);
				}
			}
		}
	}
	sort(a+1,a+1+n);
	int ans=a[n];
	for(int i=n;i>=n-m+1;i--){
		ans&=a[i];
	}
	cout << ans;
	return 0;
}
