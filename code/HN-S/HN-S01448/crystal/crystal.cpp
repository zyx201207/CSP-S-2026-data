#include<bits/stdc++.h>
using namespace std;
#define ll long long
int n,m;
ll tans,sum[500010],a[500010],annum=1e12+10,ans=0;
bool check(int l){
	for(int i=1;i<=n-l+1;i++){
		int r=i+l-1;
		if((a[r]*l)-(ll)(sum[r]-sum[i-1])<=m){
			return 1;
		}
	}return 0;
}
int find_long(){
	int l=1,r=n;
	while(l<r){
		int mid=(l+r+1)>>1;
		if(check(mid)){
			l=mid;
		}else{
			r=mid-1;
		}
	}return l;
}
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	//100pts?
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	sort(a+1,a+1+n);
	ll la=-1e12-10,num=0;
	for(int i=1;i<=n;i++){
		if(a[i]==la){
			num++;
		} else{
			la=a[i];
			num=1;
		}
		sum[i]=sum[i-1]+a[i];
		ans=max(num,ans);
	}
	cout<<find_long();
	return 0;
}
