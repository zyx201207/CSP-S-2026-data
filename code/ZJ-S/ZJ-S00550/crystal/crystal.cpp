#include <bits/stdc++.h>
#define int long long
using namespace std;
const int N=5e5+10;
int n,m,a[N];
signed main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++) cin>>a[i];
	sort(a+1,a+n+1);
	if(m==0){
		int now=0,mx=-1;
		for(int i=1;i<=n;i++){
			if(i==1){
				now++;
			}else{
				if(a[i]!=a[i-1]){
					mx=max(mx,now);
					now=1;
				}else{
					now++;
				}
			}
		}
		mx=max(mx,now);
		cout<<mx;
	}
	bool f=1;
	int k=a[2]-a[1];
	if(n>=2){
		for(int i=2;i<=n;i++){
			if(a[i]-a[i-1]!=k){
				f=0;
				break;
			}
		}
	}else{
		f=0;
	}
	if(f==1){
		int i=n;
		int ans=0;
		while(ans<m&&i>0){
			ans=k*(n-i+1)*(n-i)/2;
			i--;
		}
		cout<<n-i;
		return 0;
	}
	int ans=-1;
	for(int i=1;i<=n;i++){
		for(int j=1;j<=n;j++){
			int l=0;
			for(int k=j;k>=i;k--){
				l+=a[j]-a[k];
			}
			if(l<=m){
				ans=max(ans,j-i+1);
			}
		}
	}
	cout<<ans;
	return 0;
}