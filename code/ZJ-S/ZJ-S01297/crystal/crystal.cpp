#include<bits/stdc++.h>
using namespace std;
#define ll long long
const int N=5e5+10;
ll n,m,a[N],ans;
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	sort(a+1,a+n+1);
	ll sum=0,l=n;
	a[n+1]=a[n];
	for(int i=n;i>=1;i--){
		sum-=(a[i+1]-a[i])*(i-l);
		while(l>0){
			if(sum+(a[i]-a[l])<=m){
				sum+=(a[i]-a[l]);
				l--;
			}
			else break;
		}
		ans=max(ans,i-l);
	}
	cout<<ans;
	return 0;
}