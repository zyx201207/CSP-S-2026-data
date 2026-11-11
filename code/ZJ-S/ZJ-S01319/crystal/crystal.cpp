#include<bits/stdc++.h>
using namespace std;
#define int long long
int n,m,a[500001];
int sum[500001];
int anss;
bool check(int x,int y){
	int s=sum[y]-sum[x-1];
	return a[y]*(y-x+1)-s<=m;
}
signed main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0),cout.tie(0);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	sort(a+1,a+n+1);
	for(int i=1;i<=n;i++){
		sum[i]=sum[i-1]+a[i];
	}
	for(int i=1;i<=n;i++){
		int l=1,r=i,mid,ans;
		while(l<=r){
			mid=(l+r)/2;
			if(check(mid,i)){
				r=mid-1;
				ans=mid;
			}else{
				l=mid+1; 
			}
		}anss=max(i-ans+1,anss);
	}
	cout<<anss;
	return 0;
} 
