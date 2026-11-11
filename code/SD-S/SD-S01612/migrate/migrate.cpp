#include<bits/stdc++.h>
using namespace std;
int c,t;
int x[2000005];
int main() {
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	cin >> c >> t;
	while(t--){
		long long n,d;
		int ans=0;
		cin >> n >> d;
		if(n==1||n==2||n==3){
			cout << 0 << endl;
			break;
		}
		
		int l=1,r=l+3;
		for(int i=1;i<=n;i++){
			cin >> x[i];
		}
		while(r<=n){
			long long p=x[r]-x[l];
			//cout << p << endl;
			bool f=1;
			if(p<=d||p>=2*d)f=0;
			if(f){
				//cout << "one" << endl;
				for(int i=l;i<r;i++){
					if(x[i+1]-x[i]>=d){
						f=0;
						break;
					}
				}
			}
			if(f)ans++;
			l++;
			r++;
		}
		cout << ans << endl;
	}
	return 0;
}

