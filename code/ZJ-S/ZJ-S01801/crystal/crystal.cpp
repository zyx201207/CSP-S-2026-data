#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N=5e5+5;
int n,m,ans,a[N];
signed main(){
	ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	sort(a+1,a+n+1);
	int x=1,y=1,k=0,t=0;
	for(int i=2;i<=n;i++){
		k+=(a[i]-a[i-1])*x;
		t+=(a[i]-a[i-1]);
		while(1){
			if(k<=m){x++;break;}
			else{
				ans=max(ans,x);
				k-=t,x--,t=t-(a[y+1]-a[y]),y++;
			}
		}
	}
	cout<<ans<<"\n";
	return 0;
}
