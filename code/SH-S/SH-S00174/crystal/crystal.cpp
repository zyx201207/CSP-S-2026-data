#include<iostream>
#include<algorithm>
#define ll long long
#define i27 __int128
using namespace std;
const int MAXN=5e5+5;
i27 cf[MAXN];
ll a[MAXN];
int n;ll m;
bool check(int x){
	if(x<=1)return 1;
	if(x>n)return 0;
	i27 T=0;
	for(int i=1;i<x;i++)T+=cf[i]*i;
	if(T<=m)return 1;
	for(int i=x;i<n;i++){
		T-=a[i]-a[i-x+1];
		T+=cf[i]*(x-1);
		if(T<=m)return 1;
	}
	return 0;
}
int erfen(){
	int L=1,R=n;
	while(L<R){
		//printf("%d %d\n",L,R);
		int mid=(L+R+1)>>1;
		if(check(mid))L=mid;
		else R=mid-1;
	}
	return L;
}
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++)scanf("%lld",a+i);
	sort(a+1,a+n+1);
	for(int i=1;i<n;i++)cf[i]=a[i+1]-a[i];
	//for(int i=1;i<=n;i++)printf("%lld ",cf[i]);
	cout<<erfen();
	return 0;
} 
