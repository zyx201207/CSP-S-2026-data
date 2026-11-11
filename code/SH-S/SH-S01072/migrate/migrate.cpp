#include<bits/stdc++.h>
using namespace std;
#define ll long long
ll read(){
	char ch=getchar();ll x=0;bool p=0;
	while(ch<'0' || ch>'9'){
		if(ch=='-')p=1;
		ch=getchar();
	}
	while(ch>='0' && ch<='9')x=(x<<1)+(x<<3)+(ch^48),ch=getchar();
	if(p)return -x;
	else return x;
}
int c,t,n;
ll d,x[2000005];
namespace std1{
	void work(){
		if(n==1){
			printf("%d\n",0);
			return ;
		}
		ll y=x[2]-x[1],k=d/y;
		if(k<=1)printf("0\n");
		else printf("%lld\n",max(n-2*k+1,0LL));
	}
}
int nx[2000005];
namespace std2{
	void init(){
		int p=1;
		for(int i=1;i<=n;i++){
			while(x[p+1]-x[i]<=d && p+1<=n)p++;
			nx[i]=p;
		}
	}
	ll query(int l,int r){
		ll sum=0;
//		printf("***%d %d\n",l,r);
		for(int i=l;i<=r;i++){
			int l1=i+1,r1=nx[i];//1
			int l2=i+1,r2=i;//2
			int l3=i+1,r3=i;//3
//			int cntt=0;
			while(1){
//				cntt++;
				int p[3]={0,0,0},q[3]={0,0,0},cnt=0;
//				printf("[%d,%d],[%d,%d],[%d,%d]\n",l3,r3,l2,r2,l1,r1);
				for(int i=r1;i>=l1;i--)
					if(cnt<3)p[cnt]=1,q[cnt]=i,cnt++;
					else break;
				for(int i=r2;i>=l2;i--)
					if(cnt<3)p[cnt]=2,q[cnt]=i,cnt++;
					else break;
				for(int i=r3;i>=l3;i--)
					if(cnt<3)p[cnt]=3,q[cnt]=i,cnt++;
					else break;
//				printf("%d %d %d\n",p[0],p[1],p[2]);
//				printf("%d %d %d\n",q[0],q[1],q[2]);
				if(p[0]==1 && p[1]==0){
					l1=q[0]+1;r1=nx[q[0]];
					l2=l1;r2=l1-1;
					l3=l1;r3=l1-1;
				}else if(p[0]==1 && p[1]==1 && p[2]==0){
					l1=nx[q[1]]+1;r1=nx[q[0]];
					l2=q[0]+1;r2=nx[q[1]];
					l3=q[0]+1;r3=q[0];
				}else if(p[0]==1 && p[1]==1 && p[2]>=1){
					l1=nx[q[1]]+1;r1=nx[q[0]];
					l2=nx[q[2]]+1;r2=nx[q[1]];
					l3=q[0]+1;r3=nx[q[2]];
				}else if(p[0]==1 && p[1]>1){
					l1=nx[q[1]]+1;r1=nx[q[0]];
					l2=l1;r2=l1-1;
					l3=q[0]+1;r3=nx[q[1]];
				}else if(p[0]==2 && p[1]==0){
					l1=nx[q[0]]+1;r1=l1-1;
					l2=q[0]+1;r2=nx[q[0]];
					l3=q[0]+1;r3=l2-1;
				}else if(p[0]==2 && p[1]>=2){
					l1=nx[q[0]]+1;r1=l1-1;
					l2=nx[q[1]]+1;r2=nx[q[0]];
					l3=q[0]+1;r3=nx[q[1]];
				}else if(p[0]==3){
					l1=nx[q[0]]+1;r1=nx[q[0]];
					l2=l1;r2=r1;
					l3=q[0]+1;r3=nx[q[0]];
				}
				sum+=r2-l2+1;
				if(r1==r)break;
			}
//			printf("%d %d\n",i,cntt);
//			if(cntt>20)puts("***");
		}
		return sum;
	}
	void work(){
		init();
		int la=1;ll res=0;
		for(int i=2;i<=n;i++)
			if(x[i]-x[i-1]>d){
				res+=query(la,i-1);
				la=i;
			}
		res+=query(la,n);
		printf("%lld\n",res);
	}
}
int main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	c=read();t=read();
	while(t--){
		n=read();d=read();
		for(int i=1;i<=n;i++)x[i]=read();
		if(c==11 || c==12)std1::work();
		else std2::work();
	}
	return 0;
}
