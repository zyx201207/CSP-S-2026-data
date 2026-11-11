#include<bits/stdc++.h>
using namespace std;
#define ll long long
ll n,m,a[500004],ans=1,d[500004],q[500004],b[500004];
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	sort(a+1,a+1+n);
	for(int i=2;i<=n;i++){
		d[i]=a[i]-a[i-1];
	}
	ll l=1,sum=0;
	q[1]=1;
	for(int i=2;i<=n;i++){
		b[l]+=d[i];
		sum+=d[i]*(i-l);
		while(l<i){
			if(sum>m){
				sum-=b[l];
				b[l+1]=b[l]-d[l+1];
				l++;
			}
			if(sum<=m){
				ans=max(ans,i-l+1);
				break;
			}
		}
	}
	cout<<ans;
	return 0;
}