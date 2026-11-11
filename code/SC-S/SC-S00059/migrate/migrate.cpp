#include<bits/stdc++.h>
#define int long long 
using namespace std;
int c,T;
const int N=2e6+10;
int n,d,a[N],cha;
bool fa,fb;
signed main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin >> c >> T;
	while(T--){
		cha=-1;
		fa=fb=0;
		cin >> n >> d;
		for(int i=1;i<=n;i++){
			cin >> a[i];
			if(i>=3&&(a[i-1]-a[i-2])!=(a[i]-a[i-1])){
				fa=1;
			}
		}
		if((a[n]-a[1])<=d){
			cout << 0 << "\n";
			continue;
		}
		if(!fa){
			cha=a[2]-a[1];
			if((a[2]-a[1])>=d){
				cout << 0 << "\n";
				continue;
			}
			int ans=d/(a[2]-a[1]);
//			cout << ans << "\n";
			
			cout << n-ans*2+1 << "\n";
		}
		
	}
	return 0;
}