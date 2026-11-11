#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int M=5e5+10;
int n;
ll a[M],m;
ll sum[M];
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	cin>>n>>m;
	
	int ans=0;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	sort(a+1,a+n+1);
	for(int i=1;i<=n;i++){
		sum[i]=sum[i-1]+a[i];
		if(a[i]*i-sum[i]>m){
			break;
		}
		ans=i;
	}
	cout<<ans<<'\n';
	
	return 0;
}
