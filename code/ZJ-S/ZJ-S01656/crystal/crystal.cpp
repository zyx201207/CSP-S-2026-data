#include<bits/stdc++.h>
#define ll long long
using namespace std;
const ll N=5e5+10;
const ll MAN=5e13;
ll n,m,a[N];
int v=1;
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		if(abs(a[i])>100)v=0;
	}
	if(n==1){
		cout<<1;
		return 0;
	}
	sort(a+1,a+1+n);
	a[n+1]=MAN; 
	if(n<=5000||v){
		int las=0,ans=INT_MIN;
		for(int i=1;i<=n;i++){
			if(a[i]==a[i+1]){
				las++;
				continue;
			}
			int cnt=las+1,t=m;
			las=0;
			for(int j=i-1;j>=1;j--){
				if(a[i]==a[j])continue;
				if(t-(a[i]-a[j])>=0){
					t-=(a[i]-a[j]);
					cnt++;
				}
			}
			ans=max(ans,cnt);
		}
		cout<<ans;
		return 0;
	}
	int u=a[n]-a[n-1];
	int cnt=1;
	for(int i=n-1;i>=1;i--){
		if(m-(a[n]-a[i])>0){
			m-=(a[n]-a[i]);
			cnt++;
		}else{
			cout<<cnt;
			return 0;
		}
	}
	return 0;
}