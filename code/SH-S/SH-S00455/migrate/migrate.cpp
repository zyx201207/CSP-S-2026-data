#include<bits/stdc++.h>
using namespace std;
#define endl '\n'
typedef long long ll;
const int N=2e6+10;
ll n,d;
ll a[N];
int nxt[N];
inline void solve(){
	cin>>n>>d;
	for(int i=1;i<=n;i++)
		cin>>a[i];
	for(int i=1,j=1;i<=n;i++){
		while(j<n&&a[j+1]-a[i]<=d)
			j++;
		nxt[i]=j;
	}
	ll ans=0;
	for(int i=1;i<=n;i++){
		int l=i+1,r=nxt[i];
		bool flag=1;
		while(l<=r&&r!=nxt[r]){
			if(l<r&&flag)
				ans+=nxt[r-1]-nxt[r-2];
			else if(!flag)
				ans+=nxt[r]-nxt[r-1];
			if((flag&&nxt[r]==nxt[r-1]&&(l<r&&nxt[r-1]==nxt[r-2]))||(!flag&&nxt[r]==nxt[r-1]))
				break;
			if(nxt[r]==nxt[r-1])
				flag=0,l=nxt[r-2]+1,r=nxt[r];
			else
				l=nxt[r-1]+1,r=nxt[r];
		}
	}
	cout<<ans<<endl;
}
int main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	ios::sync_with_stdio(nullptr);
	cin.tie(0),cout.tie(0);
	int c,T;
	cin>>c>>T;
	while(T--)
		solve();
	return 0;
}
