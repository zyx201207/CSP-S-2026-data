#include<bits/stdc++.h>
#define ll long long
#define endl '\n'
using namespace std;
const int N=5e5+10;
int n;
ll a[N],m;
ll sum;
int ans;
int j;
signed main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	sort(a+1,a+n+1);
	for(int i=1;i<=n;i++){
		a[i]+=a[i-1];
	}
	for(int i=1;i<=n;i++){
		while(j<i && (a[i]-a[i-1])*(i-j)-(a[i]-a[j])>m){
			j++;
		}
		ans=max(ans,i-j);
	}
	cout<<ans;
	return 0;
} 