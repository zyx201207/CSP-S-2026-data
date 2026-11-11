#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N=1e6+9;
int n,m;
int a[N];
int fanpre[N];
int pre[N];
signed main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	int total=0;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		total+=a[i];
	}
	total+=m;
	sort(a+1,a+n+1);
	for(int i=n;i>=1;i--){
		fanpre[i]=fanpre[i+1]+a[i];
	}
	for(int i=1;i<=n;i++){
		pre[i]=pre[i-1]+a[i];
	}
	int l,r;
	l=1;
	r=1;
	int maxl=0;
	while(1){
		if(pre[l-1]+(r-l+2)*a[r+1]+fanpre[r+2]<=total){
			r++;
		}
		else{
			maxl=max(maxl,r-l+1);
			l++;
		}
		if(r==n){
			maxl=max(maxl,r-l+1);
			break;
		}
	}
	cout<<maxl<<endl;
	return 0;
}
