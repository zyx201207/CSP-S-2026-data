#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
ll n,m;
ll ans;
ll a[200010];
bool b[200010][31];
bool f[31];
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
//	ios::sync_with_stdio(0);
//	cin.tie(0);cout.tie(0);
	cin>>n>>m;
	for(int i=1;i<=n;i++) cin>>a[i];
	for(int i=29;i>=0;i--){
		ll cnt=0;
		f[i]=f[i+1];
		for(int j=1;j<=n;j++){
			if(i==29||!f[i+1]||b[j][i+1]){
				if(a[j]&(1<<i)){
					cnt++;
				}
			}
		}
		if(cnt>=m){
			f[i]=1;
			ans+=(1<<i);
			for(int j=1;j<=n;j++){
				if(i==29||!f[i+1]||b[j][i+1]){
					if(a[j]&(1<<i)) b[j][i]=1;
				}
			}
		}
	}
	cout<<ans;
	return 0;
} 
