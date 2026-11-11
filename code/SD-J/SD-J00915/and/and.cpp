#include <bits/stdc++.h>
using namespace std;
long long n,m;
long long a[500010];
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	cin >> n >> m;
	for(int i=1;i<=n;i++){
		cin >> a[i];
	}
	sort(a+1,a+n+1);
	int ans=a[1];
	for(int i=2;i<=n;i++){
		ans=ans&a[i];
	}
	if(m==1){
		cout << a[n];
	}else if(m==n){		
		cout << ans;
	}else if(m==2){
		long long ma=LLONG_MIN;
		for(int i=1;i<n;i++){
			for(int j=i+1;j<=n;j++){
				ma=max(ma,a[i]&a[j]);
			}
		}
		cout << ma;
	}else if(m==n-1){
		int res=LLONG_MIN;
		for(int i=1;i<=n;i++){
			int sum;
			for(int j=1;j<=n;j++){
				if(i!=j){
					if(j==1||(j==2&&i==1)){
						sum=a[j];
					}else{
						sum=sum&a[j];
					}
				}
			}
			res=max(res,sum);
		}
		cout << res;
	}else{
		cout << a[n];
	}
	return 0;
}
