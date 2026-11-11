#include<bits/stdc++.h>
#define ll long long
using namespace std;
const int N=500005;
ll a[N],pre[N],sum[N];
ll n,m; 
bool cmp(int a,int b){
	return a>b;
}
int erfen(int l,int r,int pos){
	if(l>=r)return l;
	int mid=(l+r)>>1;
	ll val=sum[mid]-sum[pos-1]-(mid-pos+1)*pre[pos];
	if(val<=m)erfen(mid+1,r,pos);
	else if(val>m)erfen(l,mid,pos);
}
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	scanf("%lld%lld",&n,&m);
	for(int i=1;i<=n;i++){
		scanf("%lld",&a[i]);
	}
	sort(a+1,a+n+1,cmp);
	for(int i=2;i<=n;i++){
		pre[i]=a[1]-a[i];
		sum[i]=sum[i-1]+pre[i];
	}
	int Max=-1;
	for(int i=1;i<=n;i++){
		int Pos=erfen(i,n,i);
		while(1){
			int val=sum[Pos]-sum[i-1]-(Pos-i+1)*pre[i];
			if(val>m)Pos--;
			else break;
		}
		Max=max(Max,Pos-i+1);
	}
	printf("%d",Max);
	return 0;
}
