#include<bits/stdc++.h>
using namespace std;
#define vi vector<int>
#define pii pair<int,int>
#define endl '\n'
typedef long long ll;
const int M=5e5+5;
ll n,m,a[M],ans=0;
int main(){
	ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	ll num=0,tmp=m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		num+=a[i];
	}
	sort(a+1,a+1+n);
	if(((a[1]+a[n])*n/2)==num){
		ans=1;
		ll ds=a[2]-a[1];
		for(int i=1;m>=0 && i<=n;i++){
			if(ds*i<=m){
				m-=ds*i;
				ans++;
			}
		}
	}
	else{
		ans=-1;
		ll cnt=1;
		for(int i=n;i>=1;i--){
			cnt=1;
			m=tmp;
			for(int j=i-1;j>=1 && m>=0;j--){
				ll x=a[i]-a[j];
				if(x<=m){
					m-=x;
					cnt++;
				}
				else break;
			}
			ans=max(ans,cnt);
		}
	}
	cout<<ans;
	return 0;
}
//RP++ npy不回我消息TVT  10-31 15:46:52 