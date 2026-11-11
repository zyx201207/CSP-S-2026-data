#include<bits/stdc++.h>
using namespace std;
long long n,m,a[1000005],ans,minn;
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin >> n >> m;
	for(int i = 1; i<=n; i++){
		cin >> a[i];
	}
	sort(a+1,a+n+1);
	while(m>0){
		minn = a[1];
		for(int i = 1; i<=n; i++){
			if(a[i]>minn){
				if(m-(i-1)*(a[i]-minn)>=0){
					m -= (i-1)*(a[i]-minn);
					for(int j = 1; j<i; j++){
						a[j] = a[i];
					}
					minn = a[1];
					break;
				}else{
					m = 0;
					break;
				}
			}
		}
	}
	minn = a[1];
	for(int i = 1; i<=n; i++){
		if(minn==a[i]){
			ans++;
		}
	}
	cout << ans;
	fclose(stdin);
	fclose(stdout); 
	return 0;
}
