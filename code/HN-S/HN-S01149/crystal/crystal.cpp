#include<bits/stdc++.h>
using namespace std;
#define int long long
#define endl '\n'
const int N=5e5+5;
int a[N],n,m;
bool check(int mid){
	for(int i=1;i<=n-mid+1;i++){
		int sum=0;
		for(int j=i+1;j<=i+mid-1;j++){
			sum+=(a[j]-a[j-1])*(j-i);
		}
		if(sum<=m) return 1;
	}
	return 0;
}
int find(int l,int r){
	while(l+1!=r){
		int mid=(l+r)>>1;
		if(check(mid)) l=mid;
		else r=mid;
//		cout<<"[debug]:"<<l<<' '<<r<<endl;
	}
	return l;
}
signed main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
//	freopen("crystal4.in","r",stdin);
//	freopen("out.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	sort(a+1,a+1+n);
	bool subtask1=1,subtask2=1;
	for(int i=1;i<=n;i++){
		if(a[i]!=i) subtask1=0;
		if(i!=1&&a[i]-a[i-1]!=a[2]-a[1])
			subtask2=0;
	}
	if(subtask1){
		int ans=1;
		for(int i=2;i<=n;i++){
			if(m-(i-1)<0) break;
			m-=(i-1);
			ans++;
		}
		cout<<ans<<endl;
		return 0;
	}
	if(subtask2){
		int ans=1;
		for(int i=2;i<=n;i++){
			if(m-(i-1)*(a[2]-a[1])<0)
				continue;
			m-=(i-1)*(a[2]-a[1]);
			ans++;
		}
		cout<<ans<<endl;
		return 0;
	}
	cout<<find(0,n+1)<<endl;
	return 0;
}
