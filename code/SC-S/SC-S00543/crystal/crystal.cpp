#include<bits/stdc++.h>
#define int long long
using namespace std;
int n,m,ans=2,a[100010],b[100010];
signed main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	sort(a+1,a+n+1);
	for(int i=2;i<=n;i++){
		b[i]=a[i]-a[i-1];
	}
	while(ans<=n){
		int t=(ans-1)*b[ans];
		if(m<t){
			ans--;
			break;
		}else{
			m-=t;
		}
		ans++;
	}
	cout<<ans;
	return 0;
}