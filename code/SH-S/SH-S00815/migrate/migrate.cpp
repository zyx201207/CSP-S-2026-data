#include<bits/stdc++.h>
using namespace std;
const int maxn=2e6+5;
long long n,m,a[maxn],ans,c,t;
long long sff[maxn][2],pre[maxn][2];
long long find_end(long long o1,long long o2,long long now){
	if(o1==o2){
		return o1;
	}
	long long mid=(o1+o2)/2;
	if(a[mid]-now>m){
		return find_end(o1,mid,now);
	}else{
		return find_end(mid+1,o2,now);
	}
}
long long find_start(long long o1,long long o2,long long now){
	if(o1==o2){
		return o1;
	}
	long long mid=(o1+o2)/2;
	if(now-a[mid]>m){
		return find_start(mid+1,o2,now);
	}else{
		return find_start(o1,mid,now);
	}
}
int main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	cin>>c>>t;
	while(t--){
		ans=0;
		memset(a,0,sizeof(a));
		memset(sff,0,sizeof(sff));
		memset(pre,0,sizeof(pre));
		cin>>n>>m;
		for(int i=1;i<=n;i++){
			scanf("%lld",&a[i]);
		}
		for(int i=1;i<n;i++){
			sff[i][0]=i+1;
			sff[i][1]=find_end(i+1,n,a[i]);
		}
		for(int i=n;i>=2;i--){
			pre[i][1]=i-1;
			pre[i][0]=find_start(1,i-1,a[i]);
		}
		for(int i=1;i<n;i++){
			if(sff[i][1]-sff[i][0]<1){
				continue;
			}
			if(i+3<=n){
				if(pre[i+3][1]-pre[i+3][0]>=1){
					ans++;
				}
			}
		}
		for(int i=n;i>1;i--){
			if(pre[i][1]-pre[i][0]<1){
				continue;
			}
			if(i-3>=1){
				if(sff[i+3][1]-sff[i+3][0]>=1){
					ans++;
				}
			}
		}
		cout<<ans<<endl;
	}
	return 0;
}
//Oct31==Dec25?
