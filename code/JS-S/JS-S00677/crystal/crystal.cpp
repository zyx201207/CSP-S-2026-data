#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int maxn=5e5+6;
int n;
ll m,a[maxn];
bool check(int len){
	long long minm=0;
	for(int i=1;i<=len;i++){
		minm+=a[len]-a[i];
	}
	ll curm=minm;
	for(int l=1,r=len;r<=n;l++,r++){
		minm=min(minm,curm);
		//Preparing for moving right
		/* === Step 1: Removing the left deltahight  === */
		curm-=a[r]-a[l];
		/* === Step 2: Pulling Height === */
		curm+=(a[r+1]-a[r])*(len-1);
	}
	return minm<=m;
}
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		scanf("%lld",a+i);
	}
	sort(a+1,a+1+n);
	int l=1,r=n;
	while(l<=r){
		int mid=(l+r)>>1;
		if(check(mid))l=mid+1;
		else r=mid-1;
	}
	cout<<l-1<<endl;
	return 0;
}
