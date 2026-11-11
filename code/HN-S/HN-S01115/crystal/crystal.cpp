#include<bits/stdc++.h>
using namespace std;
#define int long long
const int N=5e5+9;
int sum[N];
int a[N];
int n,m;
int mx;
bool coo(int x,int y){
	return x<y; 
}
bool check(int x,int i){
	int cur=sum[i]-sum[x-1];
	int len=i-x+1;
//	cout<<x<<' '<<i<<' '<<cur<<' '<<len<<' '<<a[i]<<'\n'; 
	if(a[i]*len-cur<=m){
//		cout<<"yes\n";
		return 1;
	}
	return 0;
}
signed main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	sort(a+1,a+n+1,coo);
	
	for(int i=1;i<=n;i++){
		sum[i]=sum[i-1]+a[i];
		int l=0,r=i+1;
		while(l+1<r){
			int mid=(l+r)>>1;
//			cout<<l<<' '<<r<<'\n';
			if(check(i-mid+1,i)){
				l=mid;
			}else{
				r=mid;
			}
		}
//		cout<<r<<' '<<i<<'\n';
		mx=max(mx,l);
	}
	cout<<mx<<'\n';
	return 0;
} 
