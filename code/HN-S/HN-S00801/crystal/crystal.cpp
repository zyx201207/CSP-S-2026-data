#include<bits/stdc++.h>
#define int long long
using namespace std;
int n,m,a[500001],s[500001],ans[500001],ss[500001];
int check(int x){
	x--;
	for(int i=1;i<=n-1;i++){
		int r=i+x-1,len=1,cnt=0;
		if(r>n-1){
			break;
		}
		cnt=ans[r]-ans[i-1]-(ss[r]-ss[i-1])*(i-1);
//		for(int j=i;j<=r;j++){
//			cnt+=len*s[j];
//			len++;
//		}
//			cout<<i<<" "<<r<<" "<<cnt<<endl;
		if(cnt<=m){
			return 1;
		}
	}
	return 0;
}
signed main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	sort(a+1,a+n+1);
	for(int i=1;i<=n-1;i++){
		s[i]=a[i+1]-a[i];
	}
	for(int i=1;i<=n-1;i++){
		ss[i]=ss[i-1]+s[i];
		ans[i]=i*s[i]+ans[i-1];
	}
	int l=1,r=n;
	while(l<=r){
		int mid=(l+r)/2;
		int x=check(mid);
//		cout<<l<<" "<<r<<" "<<mid<<" "<<x<<endl; 
		if(x==1){
			l=mid+1;
		}
		else{
			r=mid-1;
		}
	}
	cout<<l-1;
	return 0;
}
