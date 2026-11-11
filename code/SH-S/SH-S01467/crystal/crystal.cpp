#include<bits/stdc++.h>
using namespace std;
const int maxn=5e5+5;
long long n,m,a[maxn],ans=0,used=0;
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	used=0;
	ans=1;
	sort(a+1,a+n+1);
	for(int i=2;i<=n;i++){
		used+=(ans-1)*(a[i]-a[i-1])-(a[i-1]-a[i-ans]);
		if(used>m) continue;
		for(int j=i-ans;j>0;j--){
			if(used+(a[i]-a[j])<=m){
				ans++;
				used+=a[i]-a[j];
			}
			else
				break;
		}
//		cout<<i<<' '<<used<<' '<<ans<<endl;
	}
	cout<<ans<<endl;
}
