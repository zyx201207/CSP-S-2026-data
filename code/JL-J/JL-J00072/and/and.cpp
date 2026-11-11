

#include <bits/stdc++.h>
using namespace std;
long long tr[20000005];
long long ls[20000005];
long long lazy[20000005];
long long n,m;
long long tot;
long long c1;
long long rs[20000005];
long long ans;
void bu(long long val,long long wei,long long xzmm){
	for (int j=wei;j>=0;j--){
		if (((c1>>j)&1)==1){
			if (ls[xzmm]){
			}
			else{
				ls[xzmm]=++tot;
			}
			if (rs[xzmm]){
				bu(c1,j-1,rs[xzmm]);

			}
			else{
				rs[xzmm]=++tot;
				bu(c1,j-1,rs[xzmm]);
			}
			lazy[rs[xzmm]]++;
			xzmm=ls[xzmm];
		}
		else{
			if (rs[xzmm]){
				xzmm=rs[xzmm];
			}
			else{
				rs[xzmm]=++tot;
				xzmm=rs[xzmm];
			}

		}
		lazy[xzmm]++;
	}
}
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0),cout.tie(0);
	cin >> n >> m;
	for (int i=1;i<=n;i++){
		long long pos=0;
		cin >> c1;
		bu(c1,30,0);

	}
	long long xz=0;
	for (long long i=30;i>=0;i--){
		//cout << ans << '\n';
		//cout << 'b';
		if (!ls[xz] && !rs[xz]){
			//cout << i;
			break;
		}
		if (lazy[ls[xz]]>=m && ls[xz]){
			//cout << i << '\n';
			//cout << 'c';
			xz=ls[xz];
			ans+=(1ll<<i);
		}
		else{
			xz=rs[xz];
		}
	}
	cout << ans;
	//cout << tot;
	//cout << 'a';
	return 0;
}

