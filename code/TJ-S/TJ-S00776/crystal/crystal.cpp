#include<bits/stdc++.h> 
using namespace std;
#define ll long long
const int N = 5e5+10;
int n; 
ll ans = 0,minn;
ll m,a[N],sum[N];
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	sort(a+1,a+1+n);
	for(int i=2;i<=n;i++){
		sum[i] = sum[i-1] + a[i] - a[i-1];
	}
	int l=0,r=n;
	while(l<r){
		int flag = 0,vr = 1;
		ans = 0;
		int mid = (l+r+1)/2;
		for(int i=1;i<=mid;i++){
			ans += sum[mid]-sum[i];
			if(ans > m){
				vr = 0;
				break;
			}
		}
		for(int i=mid+1;i<=n;i++){
			ans = ans + sum[i]-sum[i-1]-sum[i-mid+1]+sum[i-mid];
			minn = ans;
			if(ans <= m){
				flag = 1; 
			}
		}
		if(flag == 0 && vr == 0) r = mid-1;
		else l = mid;
	}
	cout<<l;
	return 0;
}
/*
10 19768503
61 64 18 17 -54 -41 47 83 24 89

*/
