#include<bits/stdc++.h>
using namespace std;
long long c,t,n,d,x[2111111],ll[2111111],rr[2111111],ans;
void dfs(int st,int nw,bool ok,int deep,int kc,int lkc,bool isma,int lnw,int t1){
	if(ll[nw]!=lkc&&lkc!=0)return;
	if(ok&&deep-t1>=2&&ll[nw]==lkc){
		ans++;
	}
	if(isma==0)return;
	if(rr[nw]-nw&&ok==0)dfs(st,rr[nw],ok,deep+1,kc,kc,isma,nw,t1);
	if((rr[nw]-nw)&&(rr[kc]-kc)&&ok){
		for(int i=nw+1;i<=min(rr[nw],rr[kc]);i++)dfs(st,i,ok,deep+1,i,kc,(i==min(rr[nw],rr[kc])),nw,t1);
	}
	if(ok==0&&rr[nw]-nw>=2&&(ll[rr[nw]]>=nw||nw==st))dfs(st,rr[nw],1,deep+1,rr[nw]-1,kc,isma,nw,deep);
}
int main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	scanf("%lld%lld",&c,&t);
	while(t--){ans=0;
		scanf("%lld%lld",&n,&d);
		for(int i=1;i<=n;i++){
			scanf("%lld",&x[i]);
		}
		for(int i=1;i<=n;i++){
			int l=1,r=i;
			while(l<r){
				int mid=(l+r)/2;
				if(x[i]-x[mid]<=d)r=mid;
				else l=mid+1;
			}ll[i]=l;
			l=i,r=n;
			while(l<r){
				int mid=(l+r+1)/2;
				if((x[mid]-x[i])<=d)l=mid;
				else r=mid-1;
			}rr[i]=l;
		}
		for(int i=1;i<=n-3;i++)dfs(i,i,0,0,0,0,1,0,0);
		printf("%lld\n",ans);
	}
}
