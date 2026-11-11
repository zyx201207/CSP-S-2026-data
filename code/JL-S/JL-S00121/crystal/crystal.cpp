#include<bits/stdc++.h>
using namespace std;
#define int long long
int n,m,a[500100],ans;
signed main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin >> n >> m;
	for(int i=1;i<=n;++i){
		cin >> a[i];
	}
	sort(a+1,a+n+1);
	if(n>=5000){
		int k=a[2]-a[1],g=0;
		for(int i=3;i<=n;++i){
			if(a[i]-a[i-1]!=k){
				g=1;
				break;
			}
		}
		if(g==0){
			for(int i=1;i<=n;++i){
				int c=k*i*(i-1)/2;
				if(m<c){
					cout << i-1 << endl;
					return 0;
				}
			}
		}
	}
	
	for(int i=1;i<=n;++i){
		int sum=0,f=0;
		for(int j=i;j>=1;--j){
			if(sum+a[i]-a[j]<=m){
				sum+=a[i]-a[j];
			}else{
				ans=max(ans,i-j);
				f=1;
				break;
			}
		}
		if(f==0){
			ans=max(ans,i);
		}
	}
	cout << ans << endl;
	return 0;
}
