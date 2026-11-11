#include<iostream>
#include<algorithm>
using namespace std;
#define int long long
int n,m,l,r;
int a[500010],ans;
bool check(int mid){
	int sum=0;
	for(int i=1;i<=n;++i){
		if(a[i]>=mid){
			break;
		}else{
			sum+=mid-a[i];
		}
	}
	cout<<sum<<"\n";
	return sum<=m;
}
signed main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	cin>>n>>m;
	for(int i=1;i<=n;++i){
		cin>>a[i];
	}
	sort(a+1,a+n+1);
	l=a[1],r=a[n];
	while(l<r){
		int mid=l+(r-l)/2;
		if(check(mid)){
			l=mid+1;
		}else{
			r=mid;
		}
	}
	for(int i=1;i<=n;++i){
		if(a[i]<=l){
			ans++;
		}else{
			break;
		}
	}
	cout<<ans;
	return 0;
} 
