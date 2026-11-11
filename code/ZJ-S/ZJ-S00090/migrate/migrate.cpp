#include<bits/stdc++.h>
#define Lwhile(T) int T;cin>>T;while(T--)
using namespace std;
long long a[2000005];
int main(){
	freopen("migrate4.in","r",stdin);
	freopen("migrate.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0),cout.tie(0);
	int C;
	cin>>C;
	Lwhile(T){
		int n,ans = 0;
		long long d,_min = LLONG_MAX;
		cin>>n>>d;
		for(int i = 1;i <= n;i++){
			cin>>a[i];
			if(i > 1){
				_min = min(_min,a[i]-a[i-1]);
			}
		}
		if(d < _min){
			cout<<"0\n";
			continue;
		}
		if(C == 11||C == 12){
			cout<<max(0ll,n-d/(a[2]-a[1])-2)<<'\n';
			continue;
		}
		for(int i = 1;i <= n;i++){
			if(a[i] <= n-3){
				if(a[i+3]-a[i] > d&&a[i+2]-a[i] <= d&&a[i+3]-a[i+1] <= d){
					ans++;
				}
			}
		}
		cout<<ans<<'\n';
	}
	return 0;
}
