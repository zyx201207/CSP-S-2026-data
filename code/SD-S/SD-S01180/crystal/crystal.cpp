#include<bits/stdc++.h>
using namespace std;
const int N=5e5+100;
#define int long long
int n,m,x=1;
int a[N],b[N];
int ans=0;
signed main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	for (int i=1;i<=n;i++){
		cin>>a[i];
		if (i>=3 && (a[i]-a[i-1])!=(a[i-1]-a[i-2])) x=0;
	}
	sort(a+1,a+n+1);
	if (x){
		int y=a[2]-a[1];
		for (int i=1;i<=n;i++){
			if (m<0){
				ans=i-1;
				break;
			}
			m-=y;
		}
		cout<<ans<<endl;
		return 0;
	}
	for (int i=1;i<=n;i++){
		b[i]=(a[i]-a[i-1])*(i-1)+b[i-1];
	}
	for (int i=1;i<=n;i++){
		for (int j=i;j<=n;j++){
			if (m<(b[j]-b[i])){
				ans=max(ans,j-i);
				break;
			}
		}
	}
	cout<<ans<<endl;
	return 0;
}
