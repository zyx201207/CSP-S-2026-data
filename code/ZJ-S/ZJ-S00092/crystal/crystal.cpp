#include<bits/stdc++.h>
using namespace std;
#define ll long long
ll n,m;

const ll N=5e5+10;
ll a[N];
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
	ll sum=0,ans=0,p=1,num=1;
	while(sum<=m&&p<n){
		p++;
		ll now_sum=(a[p]-a[p-1])*num+sum;
		if(now_sum>m){
			break;
		}
		num++;
		sum=now_sum;
	}
	ans=num;
	ll last=1;
	for(;p<=n;p++){
		sum=(a[p]-a[p-1])*num+sum;
		if(sum>m){
			while(last<=p&&sum>m){
				sum-=a[p]-a[last];
				last++;
				num--;
			}
		}
		num++;
		ans=max(num,ans);
	}
	cout<<ans;
}
/*
Oct31==Dec25?
*/