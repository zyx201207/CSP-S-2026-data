#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
ll n,m,a[500007];
int ans=1;
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++)cin>>a[i];
	sort(a+1,a+n+1);
	ll tgt,cnt=0;//target
	for(int i=2;i<=n;i++){
		tgt=a[i];
		cnt=0;
		for(int j=1;j<=i;j++){
			cnt+=(tgt-a[j]);
		}if(cnt>m)break;
		else ans=max(ans,i);

	}
	cout<<ans;
	return 0;
}
