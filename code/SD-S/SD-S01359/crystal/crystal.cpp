#include<iostream>
#include<cstdio>
#include<algorithm>
using namespace std;
long long n,m,a[500005],b[500005],ans=0;
bool check(long long i,long long j){
	if(a[i]*(i-j)-(b[i-1]-b[j-1])<=m)return true;
	else return false;
}
long long fd(long long  i){
	long long l=1,r=i,mid=(l+r)/2;
	while(l!=r){
		if(check(i,mid))r=mid;
		else l=mid+1;
		mid=(l+r)/2;
	}
	return l;
}
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	b[0]=0;
	cin>>n>>m;
	for(long long  i=1;i<=n;i++)cin>>a[i];
	sort(a+1,a+n+1);
	for(long long  i=1;i<=n;i++)b[i]=b[i-1]+a[i];
	for(long long  i=1;i<=n;i++){
		if(i!=n)if(a[i]==a[i+1])continue;
		ans=max(ans,i-fd(i)+1);
	}
	cout<<ans;
	return 0;
}
/*
进展顺利，庆祝一下
rp++ 
*/
