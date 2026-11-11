#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N=5e5+5;
int a[N];
signed main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0),cout.tie(0);
	int n,m,ans=1,w=0;
	cin>>n>>m;
	for(int i=1;i<=n;i++) cin>>a[i];
	sort(a+1,a+1+n);
	for(int i=1,j=2;j<=n;j++){
		w+=(j-i)*(a[j]-a[j-1]);
		while(w>m){
			w-=a[j]-a[i];
			i++;
		}
		ans=max(ans,j-i+1);
	}
	cout<<ans;
	return 0;
}
