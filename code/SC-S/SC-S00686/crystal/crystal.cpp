#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
ll a[500005]={};
ll d[500005]={};
int n=0;
ll m=0;
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
	d[1]=0;
	for(int i=2;i<=n;i++){
		d[i]=a[i]-a[i-1];
	}
	int num=0;
	int ans=0;
	ll dj=0;
	for(int i=1;i<=n;i++){
		dj+=num*d[i];
		num+=1;
		while(dj>m && num>0){
			num-=1;
			dj-=a[i]-a[i-num];
		}
		ans=max(ans,num);
	}
	cout<<ans;
	return 0;
}