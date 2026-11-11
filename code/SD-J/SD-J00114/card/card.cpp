#include<bits/stdc++.h>
#define ll long long
using namespace std;
ll n,m,a[500005],T[300005];
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin>>n>>m;
	for(ll i=1;i<=n;i++)cin>>a[i];
	for(ll i=1;i<=n;i++){
		vector<ll>Q;
		for(ll j=i;j<=n;j++){
			for(ll k=0;k<Q.size();k++)
				if(Q[k]==a[j]){
					Q.erase(Q.begin()+k,Q.end());
					break;
				}
			Q.push_back(a[j]);
		} 
		for(ll k:Q)T[k]++;
	}
	for(ll i=1;i<=m;i++)
		cout<<T[i]<<' ';
	return 0;
}
//单人版小猫钓鱼（模拟），模拟牛逼！大概24~48分左右（也可能有一部分点超时） 
//建议升黑
/*谨以一首《Flower Dance》纪念我的3年OI生涯。
太坐牢了，T1简单，后面的全没想出正解/(ㄒoㄒ)/~~*/

