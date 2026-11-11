#include<bits/stdc++.h>
using namespace std;
#define int long long
#define endl '\n'
int n,m;
int a[500005],b[500005];
bool check(int x){
	for(int i=1;i+x-1<=n;i++){
		int j=i+x-1;
		if(a[j]*(x-1)-(b[j-1]-b[i-1])<=m){
			return 1;
		}
	}
	return 0;
}
signed main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		a[i]+=1e12;
		b[i]=b[i-1]+a[i];
	}
	sort(a+1,a+n+1);
	int l=1,r=5e5;
	while(l<=r){
		int mid=(l+r)/2;
		if(check(mid)){
			l=mid+1;
		}else{
			r=mid-1;
		}
	}
	cout<<r;
	return 0;
} 