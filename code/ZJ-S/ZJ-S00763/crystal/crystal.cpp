#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
int n;
ll a[500050],d[500050];
ll m;
bool flag1=0,flag2=0;
int ans=0;
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	sort(a+1,a+n+1);
	for(int i=1;i<n;i++){
		d[i]=a[i+1]-a[i];
		if(d[i]!=1)flag1=1;
		if(i>1  && d[i]!=d[i-1])flag2=1;
	}
	d[n]=0;
	if(flag1==0){
		ll k=0;
		for(int i=1;i<=n;i++){
			k+=i;
			if(k<=m)ans++;
			else break;
		}
		cout<<ans;
	}
	else if(flag2==0){
		ll k=0;
		for(int i=1;i<=n;i++){
			k+=i*d[i];
			if(k<=m)ans++;
			else break;
		}
		cout<<ans;
	}else {
		for(int i=1;i<=n;i++){
		ll m1=m;
		for(int j=i;j<=n;j++){
			if(m1-d[j]*(j-i+1)>=0){
				m1-=d[j]*(j-i+1);	
			}else break;
			ans=max(ans,j-i+1);
		}
	}
	cout<<ans+1;
	}
	
	return 0;
}