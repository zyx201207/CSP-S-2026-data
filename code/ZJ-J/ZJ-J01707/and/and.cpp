#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N=2e5+10;
int n,a[N],wt[N],t,ans,m;

signed main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0),cout.tie(0);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	for(int j=30;j>=0;j--){
		t=0;
		for(int i=1;i<=n;i++){
			if((a[i]&(1LL<<j))){
				wt[++t]=a[i];
			}
		}
		if(t>=m){
			for(int i=1;i<=t;i++){
				a[i]=wt[i];
			}
			n=t;
			ans+=(1LL<<j);
		}
	}
	cout<<ans;
	return 0;
}
