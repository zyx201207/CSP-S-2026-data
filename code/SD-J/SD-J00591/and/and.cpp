#include <bits/stdc++.h>
#define ll long long
using namespace std;
ll n,m,a[200010],ans,ma,cnt,p[200010];
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
	cin>>a[1];
	ans=a[1];
	for(int i=2;i<=n;i++){
		cin>>a[i];
		ans=ans&a[i];
	}
	if(n==m){
		cout<<ans;
		return 0;
	}
	if(m==1){
		for(int i=1;i<=n;i++) ma=max(ma,a[i]);
		cout<<ma;
		return 0;
	}
	if(m==2){
		for(int i=1;i<n;i++){
			for(int j=i+1;j<=n;j++){
				ma=max(ma,a[i]&a[j]);
			}
		}
		cout<<ma;
		return 0;
	}
	sort(a+1,a+1+n,greater<ll>());
	cout<<a[m];
	return 0;
}

