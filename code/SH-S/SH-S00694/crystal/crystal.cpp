#include<bits/stdc++.h>
using namespace std;
#define int long long
int n,m;
int arr[500005];
int minn=1e9,maxn=-1e9;
int check(int mid){
	int cnt=0;
	int i=1;
	for(;i<=n;i++){
		if(arr[i]>=mid) break;
	}
	i--;
	int cp=i;
	int cpm=m;
	for(;i>=1;i--){
		if(mid-arr[i]<=m){
			m-=(mid-arr[i]);
			cnt++;
		}
		else break;
	}
	for(i=cp+1;i<=n;i++){
		if(arr[i]==mid) cnt++;
		else break;
	}
	m=cpm;
	return cnt;
}
void solve10000(){
	sort(arr+1,arr+n+1);
	int ans=-1e9;
	int l=minn,r=maxn;
//	cout<<"l:"<<l<<"r:"<<r<<endl;
	for(;l<=r;l++){
		ans=max(ans,check(l));	
	}
	cout<<ans;
}
int pre,r;
bool B=1;
signed main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>arr[i];
		if(i==2) r=arr[i]-arr[i-1];
		if(i>2){
			if(arr[i]-arr[i-1]!=r) B=0;
		}
		minn=min(minn,arr[i]);
		maxn=max(maxn,arr[i]);
	}
	if(n<=5000||maxn-minn<=200) solve10000();
	else if(B){
		m*=2;
		int x=1;
		for(;x*(2*x-r*x-2*arr[1]+r)<=m;x++){;}
		if(x*(2*x-r*x-2*arr[1]+r)>m) x--;
		cout<<check(arr[x]);
	}
	return 0;
} 
