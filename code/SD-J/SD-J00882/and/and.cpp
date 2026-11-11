#include<bits/stdc++.h>
using namespace std;
#define N 200005
#define int long long
int n,m,a[200005],ans;
int pre[N],per[N];
int jizh[35];
bool ff=false;
signed main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	scanf("%lld%lld",&n,&m);
	for(int i=1;i<=30;i++){
		jizh[i]=jizh[i-1]*2;
	}
	for(int i=1;i<=n;i++){
		scanf("%lld",&a[i]);
		bool f=false;
		for(int j=1;j<=30;j++){
			if(jizh[j]-1==a[i]){
				f=true;
				break;
			}
		}
		if(!f){
			ff=true;
		}
	}
	if(n<=20){
		for(int i=0;i<(1<<n);i++){
			int sum=0,num=0;
			for(int j=0;j<n;j++){
				if((i>>j)&1==1){
					if(num==0){
						num++,sum=a[j+1];
					}else{
						num++,sum=sum&a[j+1]; 
					}
				}
			}
			if(num==m){
				ans=max(ans,sum);
			}
		}
		printf("%lld\n",ans);
	}else if(m==1){
		for(int i=1;i<=n;i++){
			ans=max(ans,a[i]);
		} 
		printf("%lld\n",ans);
	}else if(m==n){
		ans=a[1];
		for(int i=2;i<=n;i++){
			ans=ans&a[i];
		}
		printf("%lld\n",ans);
	}else if(n<=10000&&m==2){
		for(int i=1;i<=n;i++){
			for(int j=i+1;j<=n;j++){
				ans=max(ans,a[i]&a[j]);
			}
		}
		printf("%lld\n",ans);
	}else if(m==n-1){
		pre[0]=per[n+1]=(1<<30)-1;
		for(int i=1;i<=n;i++){
			pre[i]=pre[i]&a[i];
		} 
		for(int i=n;i>=1;i--){
			per[i]=per[i+1]&a[i];
		}
		for(int i=1;i<=n;i++){
			ans=max(ans,pre[i-1]&per[i+1]);
		}
		printf("%lld\n",ans);
	}else if(!ff){
		sort(a+1,a+1+n);
		printf("%lld\n",a[n-m+1]);
	}else{
		for(int i=30;i>=0;i--){
			int sum=0;
			for(int j=1;j<=n;j++){
				if(a[j]&(1>>i)==1){
					sum++;
				}
			}
			if(sum>=m){
				ans=ans+(1<<i);
			}
		}
		printf("%lld\n",ans);
	}
	return 0;
}
