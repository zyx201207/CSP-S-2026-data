#include<bits/stdc++.h>
#define ll long long
using namespace std;
ll n,m,a[2000009],ans,sum;
ll dp[109][109];
bool cmp(int x,int y){
	return x>y;
}
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		if(i==1) sum=a[i];
		else sum&=a[i];
	}
	sort(a+1,a+1+n,cmp);
	if(m==1){
		cout<<a[1];
	}else if(m==2){
		for(int i=1;i<=n;i++){
			for(int j=i+1;j<=n;j++){
				ans=max(ans,a[i]&a[j]);
			}
		}
		cout<<ans;
	}else if(m==n){
		cout<<sum;
	}else if(m==n-1){
		for(int i=1;i<=n;i++) ans=max(ans,sum&a[i]);
		cout<<ans;
	}else cout<<a[m];
	return 0;
}
