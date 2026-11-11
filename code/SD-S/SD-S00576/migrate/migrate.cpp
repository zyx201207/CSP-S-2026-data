#include<bits/stdc++.h>
using namespace std;
const int N=2e6+5;
int c,t,n,cntl[N],cntr[N];
unsigned long long d,x[N];
int R(int t){
	int l=t,r=n,ans=0;
	while(l<=r){
		int mid=l+r>>1;
		if(1ll*x[mid]-x[t]>1ll*d){
			r=mid-1;
		}else{
			l=mid+1;
			ans=mid;
		}
	}
	if(ans==0||ans==t)
		return -1;
	return ans;
}
int L(int t){
	int l=1,r=t,ans=0;
	while(l<=r){
		int mid=l+r>>1;
		if(1ll*x[t]-x[mid]>1ll*d){
			l=mid+1;
		}else{
			r=mid-1;
			ans=mid;
		}
	}
	if(ans==0||ans==t)
		return -1;
	return ans;
}
int main(){
	freopen("migrate.in","r",stdin);
//	freopen("migrate.out","w",stdout);
	scanf("%d%d",&c,&t);
	while(t--){
		map<pair<int,int>,bool>tt;
		scanf("%d%lld",&n,&d);
		for(int i=1;i<=n;i++){
			scanf("%lld",&x[i]);
			cntl[i]=1;
			cntr[i]=1;
		}
		for(int i=2;i<=n;i++){
			int l1=L(i),l2=L(i-1);
			if(l1!=l2&&l2!=-1){
				cntl[i]+=cntl[l1];
			}
		}
		for(int i=n-1;i>=1;i--){
			int r1=R(i),r2=R(i+1);
			if(r1!=r2&&r2!=-1){
				cntr[i]+=cntr[r1];
			}
		}
		long long ans=0;
		for(int i=1;i<=n;i++){
			int l1=L(i),l2=L(i-1),l3=L(i-2);
			int r1=R(i),r2=R(i+1),r3=R(i+2);
//			if(l1==8&&r1==10){
//				cout<<l1<<' '<<l2<<' '<<l3<<' '<<r1<<' '<<r2<<' '<<r3<<'\n';
//			}
			if(!tt[{l1,r1}]){
				if( (r1!=-1&&l1!=-1&&((l1==l2&&l1!=l3)))||(l1!=-1&&r1!=-1&&((r1==r2&&r1!=r3)))){
					if(!((r1!=-1&&((l1==l2&&l1!=l3)))&&(l1!=-1&&((r1==r2&&r1!=r3))))){
						if((r1!=-1&&((l1==l2&&l1!=l3)))){
							if(cntl[l1]==1&&cntr[r1]==1){
								if(!(x[r1]-x[l2]<=d))
									ans+=1ll*cntl[l1]*cntr[r1];
							}else
								ans+=1ll*cntl[l1]*cntr[r1];
						}
						if(l1!=-1&&((r1==r2&&r1!=r3))){
							if(cntl[l1]==1&&cntr[r1]==1){
								if(!(x[r2]-x[l1]<=d))
									ans+=1ll*cntl[l1]*cntr[r1];
							}else
								ans+=1ll*cntl[l1]*cntr[r1];
						}
					}
				}
//						cout<<l1<<' '<<r1<<' '<<1ll*cntl[l1]<<' '<<cntr[r1]<<endl;
				tt[{l1,r1}]=1;
			}
		}
		printf("%lld\n",ans);
	}
	return 0;
}
