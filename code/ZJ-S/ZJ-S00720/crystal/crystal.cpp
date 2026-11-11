#include<bits/stdc++.h>
using namespace std;
const int mn = 5e5+9;
#define ll long long
ll n,m;
int ans;
ll a[mn];
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin >> n >> m;
	for(int i=1;i<=n;i++){
		cin >> a[i];
	}
	sort(a+1,a+n+1);
	for(int i=1;i<=n;i++){
		for(int j=i;j<=n;j++){
			int l=i,r=j,cnt=0;
			while(l<r){
				cnt+=(a[r]-a[l]);
				r--;
				l++;
			}
			if(cnt<=m)
			ans = max(ans,j-i+1);
		}
	}
	cout << ans;
	return 0;
}
