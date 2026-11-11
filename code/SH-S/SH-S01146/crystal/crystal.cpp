#include<bits/stdc++.h>
#define ll long long
using namespace std;
int n;
ll m,a[500005],b[500005],ans=0;
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin.tie(0);
	cout.tie(0);
	cin>>n>>m;
	for(int i=0;i<n;i++)cin>>a[i];
	sort(a,a+n);
	for(ll i=1;i<n;i++){
		b[i]=i*(a[i]-a[i-1])+b[i-1];
	}
	for(ll i=0;i<n;i++){
		for(ll j=i+1;j<n;j++){
			if(b[j]-b[i]<=m)ans=max(ans,j-i+1);
		}
	}
	cout<<ans;
}
