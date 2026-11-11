#include<bits/stdc++.h>
#define int long long
using namespace std;
priority_queue<int>qp;
const int N=5e5+10;
int a[N];
int n,m;
bool check(int x){
	for (int l=1,r=x;r<=n;r++,l++){
	if ((a[r]-a[r-1])*x-(a[r]-a[l-1])<=m)return true;	
	}
	return false;
}
void solve(){
	cin>>n>>m;
    for (int i=1;i<=n;i++){
    cin>>a[i];	
	}
	sort(a+1,a+n+1); 
	for (int i=1;i<=n;i++){
	a[i]+=a[i-1];	
	}
	int l=1,r=n;
	while (l<r){
	int mid=(l+r+1)>>1;
	if (check(mid))
	l=mid;
	else 
	r=mid-1;	
	}
	cout<<l;
}
signed main(){
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);
	int T=1;
//	cin>>T;
    while (T--)solve();
	return 0;
}

