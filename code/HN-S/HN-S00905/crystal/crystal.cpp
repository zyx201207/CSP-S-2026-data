#include<bits/stdc++.h>
using namespace std;
const int N=5e5+5,INF=0x3f3f3f3f;
typedef long long ll;
ll n,m,t=1,sum,ans=1,a[N],c[N];
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
		c[i]=a[i+1]-a[i];
	}
	ll sum=0;
	for(int i=1;i<n;i++){
		sum=sum+c[i]*t;
		if(sum>m){
			ans=max(ans,t);
			t=0;
			sum=0;
		}
		t++;
	}
	ans=max(ans,t);
	cout<<ans;
	return 0;	
} 
