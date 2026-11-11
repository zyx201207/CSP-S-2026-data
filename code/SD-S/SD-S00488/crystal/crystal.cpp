#include<bits/stdc++.h>
using namespace std;
#define ll long long
ll n,m,a[500010],ans,m1,flag=1;
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m1;
	m=m1;
	for(int i=1;i<=n;i++){
		scanf("%d",a+i);
		if(i>=3&&a[i]-a[i-1]!=a[i-1]-a[i-2]){
			flag=0;
		}
	}
	if(flag){
		ll h=a[2]-a[1];
		while(m-h*ans>=0){
			m-=h*ans;
			ans++;
			if(ans>n){
				break;
			}
		}
		cout<<min(ans,n);
		return 0;
	}
	sort(a+1,a+n+1);
	for(int i=n;i>=2;i--){
		m=m1;
		ll sw=1;
		for(int j=i-1;j>=1;j--){
			if(m-a[i]+a[j]>=0){
				sw++;
				m=m-a[i]+a[j];
			}else{
				break;
			}
		}
		ans=max(ans,sw);
	}
	cout<<ans;
	return 0;
}
