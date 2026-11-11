#include<bits/stdc++.h>
using namespace std;
#define int long long
int n,m;
int a[500100],b[500100],ans;
signed main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++)cin>>a[i];
	if(n==1){
		cout<<"1"<<endl;
		return 0;
	}
	sort(a+1,a+1+n);
	for(int i=1;i<=n;i++){
		b[i]=b[i-1]+a[i];
	}
	for(int i=2,j=1;i<=n&&j<=n;i++){
		while(j<i&&(i-j)*a[i]-(b[i-1]-b[j-1])>m)j++;
		ans=max(ans,i-j+1);
//		cout<<ans<<' '<<j<<endl;
	}
	cout<<ans<<endl;
	return 0;
}
