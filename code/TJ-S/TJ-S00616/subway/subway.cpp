#include <bits/stdc++.h>
#define ll long long
using namespace std;

const int MAXN = 500005;
ll n,m,a[MAXN];
ll pre[MAXN];
int main(){
	freopen("subway.in","r",stdin);
	//freopen("subway.out","w",stdout);
	
	cin >> n >> m;
	for(int i=0;i<n;i++){
		cin >> a[i];
	}
	sort(a,a+n);
	for(int i=n-1;i>=0;i--){
		for(int j=n-1;j>=i+1;j--){
			pre[j]+=a[j]-a[i];
		}
	}
	for(int i=n-1;i>=0;i--){
		if(pre[i]<=m){
			cout << i+1;
			return 0;
		}
	}
	cout << 1 << '\n';
	return 0;
}
/*
#include <bits/stdc++.h>
#define ll long long
using namespace std;

const int MAXN = 500005;
ll n,m,a[MAXN];
ll pre[MAXN];
int main(){
	freopen("crystal2.in","r",stdin);
	//freopen("crystal.out","w",stdout); 
	cin >> n >> m;
	for(int i=0;i<n;i++){
		cin >> a[i];
	}
	sort(a,a+n);
	for(ll i=n-1;i>=0;i--){
		for(ll j=i-1;j>=0;j--){
			pre[i]+=a[i]-a[j];
			cout << i << "," << j << "|";
		}
	}
	for(int i=n-1;i>=0;i--){
		if(pre[i]<=m){
			cout << i+1;
			return 0;
		}
	}
	cout << 1 << '\n';
	return 0;
}
===========================================================
#include <bits/stdc++.h>
#define ll long long
using namespace std;

const int MAXN = 500005;
ll n,m,a[MAXN];
ll pre[MAXN];
ll l,r,mid,ans;
int main(){
	freopen("crystal1.in","r",stdin);
	//freopen("crystal.out","w",stdout);
	cin >> n >> m;
	for(int i=0;i<n;i++){
		cin >> a[i];
	}
	sort(a,a+n);
	l = 1;r = n;
	while(l<r){
		mid = (l+r)/2;
		for(ll j=mid-1;j>=0;j--){
			pre[mid]+=a[mid]-a[j];
		}
		cout << mid << "," << pre[mid] << "," << m << "|"; 
		if(pre[mid]<=m){
			ans = mid;
			l = mid+1;
		}else{
			r = mid-1;
		}
	}
	cout << ans+1 << '\n';
	return 0;
}
*/
