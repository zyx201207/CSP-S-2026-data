//刘子墨SN-J00731西安交通大学附属中学 
#include<bits/stdc++.h>
using namespace std;
long long n,m,a[5000000],ans;
int main(){
	freopen("and3.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	sort(a+1,a+n+1);
	ans=a[n];
	cout<<ans<<" ";
	for(int i=n-1;i>=n-m+1;i--){
		ans&=a[i];
		cout<<ans<<" ";
	}
	cout<<ans<<endl;
	return 0;
}
