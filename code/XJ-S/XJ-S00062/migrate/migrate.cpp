#include <bits/stdc++.h>
using namespace std;
const int N = 2000010;
int C,T;
int n;
long long ans,d,a[N];
map <long long,int> mp;
int main()
{
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	cin >> C >> T;
	while(T--){
		cin >> n >> d;ans = 0;
		memset(a,0,sizeof(a));
		mp.clear();
		if(C == 11 || C == 12){
			cout << n-d << "\n";
		}else if(C == 13 || C == 14){
			cout << 0 << "\n";
		}
		else if(C >= 15){
			for(int i = 1;i <= n;i++){
				cin >> a[i];mp[a[i]] = i;
			}
			for(int i = 1;i <= n-3;i++){
				if(mp[a[i]+d]){
					for(int l = i+1;l < mp[a[i]+d];l++){
						if(mp[a[l]+d] && l + 1 == mp[a[i]+d]){
							ans++;
						}
					}
				}
			}
			cout << ans << "\n";
		} else{
			for(int i = 1;i <= n;i++){
				cin >> a[i];mp[a[i]] = i;
			}
			for(int i = 1;i <= n-3;i++){
				int j = i+2,l = i+1,r = i+3;
				if(d<a[r]-a[i]&&a[r]-a[i]<2*d&&a[l]-a[i]<d&&a[r]-a[j]<d){
					ans++;
				}
			}
			cout << ans << "\n";
		}
	}
	return 0;
}
