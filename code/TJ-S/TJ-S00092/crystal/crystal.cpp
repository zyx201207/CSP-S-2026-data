//#include <bits/stdc++.h>
//#define int long long
//using namespace std;
//int a[500005],f[500005],cnt[500005];
//int n,m;
//signed main(){
//	freopen("crystal.in","r",stdin);
//	freopen("crystal.out","w",stdout);
//	
//	cin>>n>>m;
//	
//	for (int i = 1;i<=n;i++){
//		cin>>a[i];
//	}
//	
//	sort(a+1,a+n+1);
//	
//	f[1] = 1;
//	cnt[1] = 0;
//	int ans = 1;
//	for (int i = 2;i<=n;i++){
//		int cst = cnt[i-1] + f[i-1]*(a[i]-a[i-1]);
//		if (cst<=m){
//			f[i] = f[i-1]+1;
//			cnt[i] = cst;
//			ans = max(f[i],ans); 
//			continue;
//		}
//		int j;
//		for(j = i-f[i-1];j<i;j++){
//			cst-=(a[i]-a[j]);
//			if (cst<=m){
//				j++;
//				break;
//			}
//		}
//		f[i] = i-j+1;
//		cnt[i] = cst;
//		ans = max(f[i],ans); 
//	}
//	
//	cout<<ans;
//	
//	return 0;
//} 


#include <bits/stdc++.h>
#define int long long
using namespace std;
int a[500005],f[500005],cnt[500005];
int n,m;
signed main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	
	cin>>n>>m;
	
	for (int i = 1;i<=n;i++){
		scanf("%lld",&a[i]);
	}
	
	sort(a+1,a+n+1);
	
	f[1] = 1;
	cnt[1] = 0;
	int ans = 1;
	for (int i = 2;i<=n;i++){
		int cst = cnt[i-1] + f[i-1]*(a[i]-a[i-1]);
		if (cst<=m){
			f[i] = f[i-1]+1;
			cnt[i] = cst;
			ans = max(f[i],ans); 
			continue;
		}
		int j;
		for(j = i-f[i-1];j<i;j++){
			cst-=(a[i]-a[j]);
			if (cst<=m){
				j++;
				break;
			}
		}
		f[i] = i-j+1;
		cnt[i] = cst;
		ans = max(f[i],ans); 
	}
	
	cout<<ans;
	
	return 0;
} 
