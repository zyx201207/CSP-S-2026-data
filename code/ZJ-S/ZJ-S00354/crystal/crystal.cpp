#include<bits/stdc++.h>
#define ll long long
using namespace std;
ll n,m,a[500005],ans;
int main(){
	ios::sync_with_stdio(0);
	cin.tie(0),cout.tie(0);
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	for(int i = 1;i<=n;i++){
		cin>>a[i];
	}
	sort(a+1,a+n+1);
	int sum = 0;
	int j = 1;
	for(int i = 1;i<=n;i++){
		while(j<n&&ans+(a[j+1]-a[j])*(j-i+1)<=m){
			ans += (a[j+1]-a[j])*(j-i+1);
			j++;
		}
		sum = max(sum,j-i+1);
		ans -= a[j]-a[i];
	}
	cout<<sum;
	return 0;
}
