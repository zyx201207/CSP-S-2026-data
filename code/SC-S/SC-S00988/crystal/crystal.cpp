#include<bits/stdc++.h>
using namespace std;
unsigned long long n,m;
long long a[500005];
long long sum[500005];
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0),cout.tie(0);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i]; 
	}
	sort(a+1,a+1+n);
	for(int i=1;i<=n;i++){
		sum[i]=(a[i]-a[i-1])*(i-1)+sum[i-1];
	}
	long long cnt=1;
	int l=1,r=n;
	while(l<=r){
		int mid=(l+r)/2;
		long long ou=sum[mid];
		if(ou<=m){
			l=mid+1;
			cnt=mid;
		}else{
			r=mid-1;
		}
	}
	cout<<cnt;
	return 0;
}