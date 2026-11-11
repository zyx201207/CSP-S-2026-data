#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
ll n,m;
vector<int> a;
bool check(int mid){//changdu
	bool f=0;
	for(int l=1;l<=n-mid+1;l++){
		int r=l+mid-1;
		int s=a[r]-a[l-1];
		int mx=a[r]-a[r-1];
		if(mx*mid-s<=m){
			f=1;
			break;
		}
	}
	return f;
}

int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
	cin>>n>>m;
	a.assign(n+5,0);
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	sort(a.begin()+1,a.begin()+1+n);
	
	for(int i=1;i<=n;i++){
		a[i]+=a[i-1];
	}
	
	int l=1,r=n;
	while(l<r-1){
		int mid=l+(r-l)/2;
		if(check(mid)){
			l=mid;
		}else{
			r=mid-1;
		}
	}
	cout<<l;

	return 0;
}
/*
5 5
1 2 4 8 9

5 8
-3 -1 2 2 7
*/