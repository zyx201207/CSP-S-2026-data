#include<bits/stdc++.h>
using namespace std;
long long n,m,a[200005],ans,ans1;
bool cmp(int x,int y){
	return x>y;
} 
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
	for(long long i=1;i<=n;i++){
		cin>>a[i];
	}
	sort(a+1,a+n+1,cmp);
	ans=a[1];
	for(int i=1;i<=n;i++){
		if(a[i]==a[i+1]){
			ans1=a[i];
			break;
		}
	}
	for(long long i=2;i<=m;i++){
		ans&=a[i];
	}
	if(m==1){
		cout<<a[1];
		return 0;
	}
	else if(m==n){
		long long cnt=a[1];
		for(int i=2;i<=n;i++){
			cnt&=a[i];
		}
		cout<<cnt;
		return 0;
	}
	else if(m==n-1){
		long long cnt=a[1];
		for(int i=2;i<n;i++){
			cnt&=a[i];
		}
		cout<<cnt;
		return 0;
	}
	cout<<max(ans1,ans);
	return 0;
}
