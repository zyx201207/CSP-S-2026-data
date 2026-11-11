#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
constexpr int N=5e5+5;
int n;
ll m;
ll a[N];

int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	sort(a+1,a+n+1);
	ll s=0;
	int l=1;
	int ans=0;
	for(int r=1;r<=n;r++){
		s+=a[r];
		while((r-l+1)*a[r]-s>m){
			s-=a[l];
			l++;
		}
		ans=max(ans,r-l+1);
	}
	cout<<ans;
	return 0;
} 
