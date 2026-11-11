#include<bits/stdc++.h>
#define ll long long
using namespace std;
ll n,m,a[500005],cha[500005],pre[500005],ans=0;
bool cmp(ll x,ll y){
	return x>y;
}
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	sort(a+1,a+1+n,cmp);
	pre[1]=0;
	for(int i=1;i<=n;i++){
		cha[i]=a[1]-a[i];
	}
	for(int i=1;i<=n;i++){
		pre[i]=0;
		for(int j=i;j<=n;j++){
			pre[j]=pre[j-1]+(cha[j]-cha[i]);
		}
		ll pos=upper_bound(pre+i,pre+n+1,m)-pre-1;
		ans=max(ans,pos-i+1);
	}
	cout<<ans;
	return 0;
}
