#include<bits/stdc++.h>
using namespace std;
const int N=10005;
int n,m,a[N];
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	for(int j=1;j<=n;j++)cin>>a[N];
	sort(a+1,a+1+n);int t,ans,b;
	for(int h=1;h<=m;h++){
		if(a[N]+t==a[N+1]){
			ans++;
		}
		if(a[N+1]+b==a[N+2]){
			ans++; 
		}
	}
	if(ans%2==0){
		ans=ans/2;
	}
	else{
		ans=(ans-1)/2;
	}
	cout<<ans<<endl;
	return 0;
}
 
