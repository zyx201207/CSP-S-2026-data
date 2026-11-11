#include<bits/stdc++.h>
using namespace std;
long long n,m;
long long a[200010];
bool cmp(long long x,long long y){
	return x<y;
}
signed main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
	long long sum=0;
	for(long long i=0;i<n;i++){
		cin>>a[i];
	}
	sort(a,a+n,cmp);
	if(m==1){
		cout<<a[n-1];
		return 0;
	}else if(m==2){
		cout<<(a[n-1]&a[n-2]);
		return 0;
	}
//	for(int i=0;i<n;i++){
//		cout<<a[i]<<" ";
//	}
//	cout<<endl;
	for(long long i=m+1;i>m-1;i--){
		sum=(a[i]&a[i-1]);
//		cout<<sum<<endl;
	}
	cout<<sum;
	return 0;
}

