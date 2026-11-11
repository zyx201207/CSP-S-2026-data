#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N=5e5+10,M=3e3+10;
ll n,m,a[N],ans[M];
void solve(ll ju){
	ll cnt=0,b[N],ans=0;
	for(int i=1;i<=n;i++){
		cnt++;
		b[cnt]=a[i];
		for(int j=1;j<=n;j++){
			if(a[j]==a[i]){
				for(int k=j;k<=n;k++){
					a[k]=0;
					cnt-=(n-j+1);
				}
			}
			else b[cnt]=a[i];
		}
	}
	for(int i=1;i<=cnt;i++){
		if(b[i]==ju)ans++;
	}
	cout<<ans<<" ";
}
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	cin>>n>>m;
	for(int i=1;i<=n;i++)cin>>a[i];
	for(int i=1;i<=n;i++)solve(i);
}