#include<bits/stdc++.h>
using namespace std;
const int N=5e5+10;
int n,l=1,r,ans;
long long m,a[N];
map<long long,int>pn;int mn;
bool ch(int x){
	long long sum=0,ix;int nm;
	for(int i=1;i<=n-x+1;i++){
		ix=a[i+x-1],sum=0,nm=i+x-1;
		for(int j=i;j<nm;j++){
			sum+=(ix-a[j]);
		}
		if(sum<=m)return 1;
	}
	return 0;
}
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	scanf("%d%lld",&n,&m),r=n;
	for(int i=1;i<=n;i++)scanf("%lld",&a[i]),pn[a[i]]++,mn=max(mn,pn[a[i]]);
	if(!m){printf("%d",mn==1?0:mn);return 0;}
	sort(a+1,a+n+1);
	while(l<=r){
		int mi=(l+r)>>1;
		if(ch(mi))ans=mi,l=mi+1;
		else r=mi-1;
	}
	if(ans==1)printf("0");
	else printf("%d",ans);
	return 0;
}
