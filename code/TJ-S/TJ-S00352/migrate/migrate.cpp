#include <bits/stdc++.h>
using namespace std;
#define int long long
const int N=2*1e6+10;
int c,t,n,d;
int a[N];

void work_one (){
	while (t--){
		cin >> n >> d;
		for (int i=1;i<=n;i++) cin >> a[i];
		if (n==1){
			cout << '0' << '\n';
			continue;
		}
		int l=a[2]-a[1];
		if (d<2*l){
			cout << '0' << '\n';
		}
		else{
			cout << n-(d/l+1) << '\n';
		}
		
	}
	return;
}

signed main (){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0),cout.tie(0);
	
	cin >> c >> t;
	if (c==11 || c==12){
		work_one();
		return 0;
	}
	else{
		while (t--){
			cin >> n >> d;
			int p[n];
			for (int i=1;i<=n;i++) cin >> a[i];
			for (int i=1;i<=n;i++) p[i]=p[i-1]+a[i];
			int ans=0;
			for (int i=1;i<=n;i++){
				for (int j=i+1;j<=n;j++){
					string vis1,vis2;
					for (int k=i;k<=j;){
						int w=k+1;
						while (p[w]-p[k-1]<=d && w<=j) w++;
						vis1=vis1+(char)(w+'0');
						k=w;
					}
					for (int k=j;k>=i;){
						int w=k-1;
						while (p[k]-p[w-1]<=d && w>=i) w--;
						vis2=(char)(w+'0')+vis2;
						k=w;
					}
					if (vis1==vis2) ans++;
				}
			}
			cout << ans << '\n';
		}
	}
	return 0;
}
