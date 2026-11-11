//csl,I love you.
#include <bits/stdc++.h>
using namespace std;
#define int long long
#define endl "\n"
#define N 1000020
#define iscc ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
int n,m;
int a[N];
int ans;

bool check(int mid){
	int cnt=0;
	for(int i=1;i<=n;i++){
		if(a[i]<mid){
			cnt+=mid-a[i];
		}
	}
	return cnt<=m;
}
signed main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	//system("fc test.out test.ans\n");
	iscc
	cin>>n>>m;
	int l=INT_MIN,r=INT_MIN;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		l=min(l,a[i]);
		r=max(r,a[i]);
	}
	
	while(l<=r){
		int mid=(l+r)/2;
		if(check(mid)){
			ans=mid;
			l=mid+1;
		}else{
			r=mid-1;
		}
	}
	
	int sum=0;
	for(int i=1;i<=n;i++){
		if(a[i]<=ans) sum++;
	}
	cout<<sum;
	return 0;
}


