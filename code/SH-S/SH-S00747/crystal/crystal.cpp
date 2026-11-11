#include<bits/stdc++.h>
using namespace std;
#define int long long
const int maxn=5e5+5;
int n,m;
int a[maxn];
int sum[maxn];
bool check(int i,int j){
	return (a[i]*(i-j)-sum[i-1]+sum[j-1]<=m); 
}
signed main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}sort(a+1,a+n+1);
	for(int i=1;i<=n;i++){
		sum[i]=sum[i-1]+a[i];
	}
	int ans=0;
	for(int i=1;i<=n;i++){
		int l=1,r=i;
		while(l<=r){
			int mid=l+(r-l)/2;
			if(check(i,mid)){
				r=mid-1;
			}else{
				l=mid+1;
			}
		}
	//	cout<<i<<':'<<r<<endl;
		ans=max(ans,i-r);
	}cout<<ans<<endl;
	return 0;
} 
