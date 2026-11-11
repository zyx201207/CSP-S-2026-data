#include <bits/stdc++.h>
#define int long long
using namespace std;

int f[5005][5005],cnt[5005][5005],a[5005];
signed main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	int c,t;
	cin>>c>>t;
	for (int T = 1;T<=t;T++){
		int n,k;
		cin>>n>>k;
		int ans= 0;
		for (int i = 1;i<=n;i++)cin>>a[i];
		
		for (int i = 0;i<=n;i++){
			for (int j = 0;j<=n;j++)
				f[i][j] = -1,cnt[i][j] = 0;
		}
		
		for (int i = 1;i<=n;i++){
			f[i][i] = 0;
			for (int j = i+1;j<=n;j++){
				if (a[j]<=a[i]+k){
					f[i][j] = 1;
					cnt[i][j] = 1;	
					continue;
				}
				int lft = lower_bound(a+i,a+j+1,a[j]-k)-a;
				//cout<<"I"<<" "<<i<<"J"<<" "<<j<<" "<<lft<<endl;
				if (f[i][lft] == -1)break;
				f[i][j] = f[i][lft] + 1;
				
				//??
				cnt[i][j] = cnt[i][lft];
				if (cnt[i][j]>2)continue;
				for (int rit = lft+1;rit<j;rit++){
					if (f[i][rit] == f[i][lft])cnt[i][j]++;
					if (cnt[i][j]>2)break;
				}
				if (cnt[i][j]>2)continue;
				if (cnt[i][j] == 2)ans++;
			} 
		}
//		for (int i = 1;i<=n;i++){
//			for (int j = 1;j<=n;j++){
//				cout<<f[i][j]<<" ";
//			}
//			cout<<endl;
//		}
//		for (int i = 1;i<=n;i++){
//			for (int j = 1;j<=n;j++){
//				cout<<cnt[i][j]<<" ";
//			}
//			cout<<endl;
//		}
		cout<<ans<<endl;
	}
	
	return 0;
}
