#include<bits/stdc++.h>
using namespace std;
int n;
long long val[500003],ch[500003],trv[500003],sum[500003],m;
long long work(int str,int lst){
	return trv[lst]-trv[str-1]-(sum[lst]-sum[str-1])*(str-1);
}
int solv(int str){
	int l=str,r=n;
	while(l<=r){
		int mid=(l+r)/2;
		if(work(str,mid)<=m) l=mid+1;
		else r=mid-1;
	}
	return l-str;
}
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	scanf("%d%lld",&n,&m);
	for(int i=1;i<=n;i++) scanf("%lld",&val[i]);
	sort(val+1,val+n+1);
	ch[0]=trv[0]=sum[0]=ch[1]=trv[1]=sum[1]=0;
	for(int i=2;i<=n;i++){
		ch[i]=val[i]-val[i-1];
		trv[i]=trv[i-1]+ch[i]*(i-1);
		sum[i]=sum[i-1]+ch[i];
	}
	int ans=0;
	for(int i=1;i<=n;i++) ans=max(ans,solv(i));
	printf("%d\n",ans);
	return 0;
}