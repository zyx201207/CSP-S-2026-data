#include <bits/stdc++.h>
#define ll long long
#define ull unsigned long long
#define pb push_back
#define pii pair<int,int>
#define fi first
#define se second
using namespace std;
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	int n;
	ll m;
	cin>>n>>m;
	vector<ll> A(n+1),pre(n+1);
	for(int i=1;i<=n;i++)
		cin>>A[i];
	sort(A.begin()+1,A.end());
	for(int i=1;i<=n;i++)
		pre[i]=pre[i-1]+A[i];
	int ans=0;
	for(int i=1;i<=n;i++){
		int l=1,r=i,mid=i;
		while(l<r){
			mid=l+r>>1;
			if(1ll*A[i]*(i-mid+1)-(pre[i]-pre[mid-1])<=m)  r=mid;
			else  l=mid+1;
		}
		ans=max(ans,i-l+1);
	}
	cout<<ans;
	return 0;
}