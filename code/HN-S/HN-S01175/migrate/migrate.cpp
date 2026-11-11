#include<bits/stdc++.h>
#define MAXN 2000010
using namespace std;
typedef long long ll;
int c,T,n;
ll d,x[MAXN];
inline int NxtFS(int index){
	int l=index+1,r=n,res=-1;
	while(l<=r){
		const int mid=(l+r)>>1;
		if(x[mid]-x[index]<=d){
			l=mid+1;
			res=mid;
		}else{
			r=mid-1;
		}
	}
	return res;
}
inline int PreFS(int index){
	int l=1,r=index-1,res=-1;
	while(l<=r){
		const int mid=(l+r)>>1;
		if(x[index]-x[mid]<=d){
			r=mid-1;
			res=mid;
		}else{
			l=mid+1;
		}
	}
	return res;
}
namespace Subtask1{
	int Main(){
		ll ans=0;
		scanf("%d %lld",&n,&d);
		for(int i=1;i<=n;++i){
			scanf("%lld",&x[i]);
		}
		for(int l=1;l<=n;++l){
			for(int r=l+2;r<=n;++r){
				const int a=NxtFS(l),b=PreFS(r);
				if(a==b+1&&x[r]-x[a]<=d&&x[b]-x[l]<=d){
					++ans;
				}
			}
		}
		printf("%lld\n",ans);
	}
}
namespace Subtask3{
	int Main(){
		scanf("%d %lld",&n,&d);
		for(int i=1;i<=n;++i){
			scanf("%lld",&x[i]);
		}
		ll ans=0;
		for(int i=1;i<=n;++i){
	//		printf("%d %d\n",PreFS(i),NxtFS(i));
			if(PreFS(i)==-1||NxtFS(i+1)==-1||x[i+1]-x[i]>d){
				continue;
			}
			int LeftL=PreFS(i+1),RghtR=NxtFS(i);
			int LeftR=PreFS(i+2),RghtL=NxtFS(i-1);
	//		printf("%d:[%d,%d] * [%d,%d]\n",i,LeftL,LeftR,RghtL,RghtR);
			if(RghtR<RghtL||LeftR<LeftL){
				continue;
			}
			for(int l=LeftL;l<=LeftR;++l){
				for(int r=RghtL;r<=RghtR;++r){
					if(x[r]-x[l]>d){
						++ans;
					}
				}
			}
		}
		printf("%lld\n",ans);
	}
}
int main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	scanf("%d %d",&c,&T);
	while(T--){
		Subtask1::Main();
	}
	return 0;
}
