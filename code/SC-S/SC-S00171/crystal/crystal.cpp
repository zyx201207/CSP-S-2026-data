#include<bits/stdc++.h>
#define int long long
using namespace std;
int n,m,a[500001],x,ans,s;
bool flag=1;
signed main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0),cout.tie(0);
	cin>>n>>m;
	for(int i = 1;i<=n;i++){
		cin>>a[i];
		if(i==2){
			x=a[i]-a[1];
		}
		if(i!=1&&a[i]-a[i-1]!=x){
			flag=false;
		}
	}
	sort(a+1,a+n+1);
	if(flag){
		s=m;
		for(int i = 1;i<=n;i++){
			if((i-1)*(a[i]-a[i-1])<=s){
				ans=max(ans,i);
				s-=(i-1)*(a[i]-a[i-1]);
			}
		}
		cout<<ans;
		return 0;
	}
	for(int i = 1;i<=n;i++){
		s=m;
		for(int j = i;j<=n;j++){
			if((j-i)*(a[j]-a[j-1])<=s){
				ans=max(ans,j-i+1);
				s-=(j-i)*(a[j]-a[j-1]);
			}
			else{
				break;
			}
		}
	}
	cout<<ans;
	return 0;
} 