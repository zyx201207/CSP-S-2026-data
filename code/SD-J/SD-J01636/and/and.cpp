#include<bits/stdc++.h>
#define int long long
using namespace std;
bool bj[40][200005];
int n,m,a[200005],cnt[200005],ans=(1<<30)-1;
signed main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	for(int i=1;i<=n;i++){
		bj[30][i]=1;
	}
	for(int base=29;base>=0;base--){
		for(int i=1;i<=n;i++){
			if(bj[base+1][i]&&a[i]&(1<<base)){
				bj[base][i]=1;
				cnt[base]++;
			}
		}
		if(cnt[base]<m){
			for(int i=1;i<=n;i++){
				if(bj[base+1][i]){
					bj[base][i]=1;
				}
			}
		}
	}
	for(int i=1;i<=n;i++){
		if(bj[0][i]){
			ans&=a[i];
		}
	}
	cout<<ans;
	return 0;
}

