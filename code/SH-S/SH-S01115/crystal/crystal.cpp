#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N=5e5+10;
int n,ans=1;
ll m,a[N],x[N];
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0),cout.tie(0);
	cin>>n>>m;
	for(int i=1;i<=n;i++)cin>>a[i];
	sort(a+1,a+n+1);
	for(int i=1;i<=n;i++)x[i]=a[i]+x[i-1];
	for(int i=2;i<=n;i++){
		if(m+(x[i-1]-x[i-ans-1])<a[i]*ans)continue;
		else{
			while(((m+(x[i-1]-x[i-ans-1]))>=a[i]*ans)&&i-ans>=1)ans++;
		}
	}
	cout<<ans<<'\n';
	return 0;
}
