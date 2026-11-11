#include<bits/stdc++.h> 
using namespace std;
long long a[500010];
int cnt[1000][1000];
int main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	int n,c,t,ans=0,d;
	cin >> c >> t;
	while(t--){
		ans=0;
		cin >> n >> d;
		for(int j=1;j<=n;j++){
			cin >> a[j];
		}
		for(int j=1;j<=n;j++){
			for(int k=j+1;k<=n;k++)
				for(int h=k+1;h<=n;h++){
					if((a[k]-a[j])<=d&&(a[h]-a[k])<=d)
						cnt[j][h]++;
						if(cnt[j][h]==2)
							ans++;
						else if(cnt[j][h]>2)
							ans--;
				}
		}
		cout << ans << "\n";
	}
	return 0;
} 