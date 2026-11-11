#include<bits/stdc++.h>
using namespace std;
long long c,T,n,d,ans,cnt,a[2100000];
void dfs(long long u,long long e,long long step,long long ms){
	if(step>ms){
		return ;
	}
	if(u==e){
		cnt++;
		return ;
	}
	for(long long i=u+1;i<=e;i++){
		if(a[i]-a[u]<=d){
			dfs(i,e,step+1,ms);
		}else{
			break;
		}
	}
}
bool f(long long u,long long v){
	long long x=a[u];
	long long lst=-1;
	long long Min=0;
	while(1){
		Min++;
		x+=d;
		long long l=1,r=n,wz=-1;
		while(l<=r){
			long long mid=(l+r)/2;
			if(a[mid]<=x){
				wz=mid;
				l=mid+1; 
			}else{
				r=mid-1;
			}
		} 
		if(wz==lst){
			return 0;
		}
		lst=wz;
		x=a[wz];
		if(wz>=v){
			break;
		}
	}
	cnt=0;
	dfs(u,v,0,Min); 
	if(cnt==2) return 1;
	else return 0;
}
int main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	cin>>c>>T;
	while(T--){
		cin>>n>>d;
		long long  gc=-1;
//		bool flaga=1;
		for(long long i=1;i<=n;i++){
			scanf("%lld",&a[i]);
//			if(i==2){
//				gc=a[i]-a[i-1];
//			}else if(i>2){
//				if(a[i]-a[i-1]!=gc){
//					flaga=0;
//				}
//			}
		}
//		if(flaga){
//			long long jmp=d/gc;
//			if(jmp<d||jmp>2){
//				cout<<0<<"\n";
//			}else{
//				jmp+=2;
//				cout<<max(0ll,n-jmp+1)<<"\n";
//			}
//			continue;
//		}
		ans=0;
		for(long long i=1;i<=n;i++){
			for(long long j=i;j<=n;j++){
				if(f(i,j)){
					ans++;
				} 
			}
		}
		cout<<ans<<"\n";
	}
	return 0;
} 
