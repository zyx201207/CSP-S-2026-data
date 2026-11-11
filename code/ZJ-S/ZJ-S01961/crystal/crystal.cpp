#include<bits/stdc++.h>
using namespace std;
long long n,m,a[500010],ans;
bool check(long long num){
	for(int i=num;i<=n;i++){
		//cout<<num*(a[i]-a[i-1])-a[i]+a[i-num]<<endl<<m<<endl;
		if(num*(a[i]-a[i-1])-a[i]+a[i-num]<=m){
			return 1;
		}
	}
	return 0;
}
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	sort(a+1,a+1+n);
	for(int i=2;i<=n;i++){
		a[i]+=a[i-1];
	}
	long long left=1,right=n;//合并个数 
	while(left<=right){
		long long mid=(left+right)/2;
		if(check(mid)){
			ans=mid;
			left=mid+1;
		}else{
			right=mid-1;
		}
		//cout<<mid<<endl<<endl;
	}
	//for(int i=1;i<=n;i++){
	//	cout<<a[i]-a[i-1]<<" "; 
	//}
	//cout<<endl;
	cout<<ans;
	return 0;
} 
