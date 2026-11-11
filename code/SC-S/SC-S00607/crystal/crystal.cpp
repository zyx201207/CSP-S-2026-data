#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cmath>
using namespace std;
const int mx=5e5+10;
typedef long long ll;
ll a[mx],n,m,cz;
int ans,max1=-1;
bool f=0;
int check(int x,ll k){
	int sum=1;
	for(int i=x-1;i>=1;i--){
		if((k-a[x]+a[i])>=0){
			sum++;
			k=k-a[x]+a[i];
		}
		else break;
	}
	return sum;
}
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		if(i==2){
			cz=a[i]-a[i-1];
		}
		else if(i>=3){
			if(cz!=a[i]-a[i-1])f=1;
		}
	}
	if(!f){
		ans=check(n,m);
		cout<<ans;
		return 0;
	}
	sort(a+1,a+1+n);
	for(int i=1;i<=n;i++){
		ans=check(i,m);
		max1=max(max1,ans);
	}
	cout<<max1;
	return 0;
} 