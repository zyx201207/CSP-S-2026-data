#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll maxn=500010;
static ll n,a[maxn],m;
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cin>>n>>m;for(int i=1;i<=n;i++)cin>>a[i]; 
	sort(a+1,a+n+1);//sort all the crystals
	ll ans=1;
	//we can prove that if we use an existed crystal energy, it is the best.
	for(int i=1;i<=n;i++){
		ll tmp=0,tpans=1,mubiao=a[i];//这颗宝石自己就得算上了，我们遍历所有 
		for(int j=i-1;j>=1;j--){//现在后面一定比前面大了，而且最靠近的代价最小 
			if(mubiao-a[j]>m-tmp)break;
			tmp+=mubiao-a[j];
			tpans++;
		}
		ans=max(ans,tpans);
	}
	cout<<ans;return 0;

}
