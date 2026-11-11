#include<bits/stdc++.h>
using namespace std;

typedef long long ll;
const ll N=500005;
ll m,a[N],q[N],ans=0;
int n;
int main(){
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);

	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	sort(a+1,a+n+1);
	for(int i=1;i<=n;i++) q[i]=q[i-1]+a[i];
	int s=0;
	for(int i=2;i<=n;i++){
		for(int j=s;j<i;j++){
			if(a[i]*(i-j)-q[i]+q[j]<=m){
				ans=max(ans,ll(i-j));
				s=j;
				break;
			}
			if(j==i-1) s=j;
		}
	}
	cout<<ans;
	return 0;
}


















