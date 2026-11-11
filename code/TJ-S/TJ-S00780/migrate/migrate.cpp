#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N=2*1e6+10;
ll a[N];
int main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	int c,t;
	cin >> c >> t;
	while(t--){
		int n;
		long long d;
		cin >> n >> d;
		for(int i=1;i<=n;i++){
			cin >> a[i];
		}
		int ans=0;
		if(c==11 || c==12){
			for(int i=d+1;i<=n;i++){
				if(d!=2)ans+=(d+2)/d*(n-d-1)-n/d;
				else ans+=(d+1)/d*(n-d-1);
			}
		}else {
			for(int i=1;i<=n;i++){
				if(a[i]-a[i-1]<=d)ans+=2;
			}
		}
		cout << ans << endl;
	}
	return 0;
} 
