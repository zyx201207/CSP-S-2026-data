#include<bits/stdc++.h>
using namespace std;
const int N=2e5+5;
int n,m,x,cnt1,sum1;
long long ans;
int a[N][32],cnt[N],f[N];
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	scanf("%d%d",&n,&m);
	for(int i=1;i<=n;i++){
		scanf("%d",&a[i][0]);
	}
	if(m==1){
		for(int i=1;i<=n;i++){
			ans=max(ans,1ll*a[i][0]);
		}
		cout<<ans;
	}
	else if(m==2){
		int o=-21;
		int fff=1;
		for(int i=1;i<=n;i++){
			o=max(o,a[i][0]);
		}
		for(int i=1;i<=n;i++){
			for(int j=1;j<=n;j++){
				if(a[i][0]<=o/2){
					break;
				}
				if(a[i][0]==a[j][0]&&fff==1){
					fff=0;
				}
				else{
					ans=max(ans,1ll*(a[i][0]&a[j][0]));
				}
			}
		}
		cout<<ans;
	}
	else if(m==n){
		ans=1ll*a[1][0];
		for(int i=1;i<=n;i++){
			ans=ans&(1ll*a[i][0]);
		}
		cout<<ans;
	}
//	for(int i=1;i<=n;i++){
//		f[i]=1;
//	}
//	for(int i=1;i<=n;i++){
//		scanf("%d",&x);
//		a[i][0]=x;
//		while(x!=0){
//			if(x%2==1){
//				a[i][++cnt[i]]=1;
//			}
//			else{
//				a[i][++cnt[i]]=0;
//			}
//			x/=2;
//		}
//		cnt1=max(cnt1,cnt[i]);
//	}
//	while(sum1<m){
//		for(int i=1;i<=n;i++){
//			if(cnt[i]==cnt1){
//				sum1++;
//			}
//		}
//		if(sum1>=m){
//			break;
//		}
//		if(sum1<m){
//			for(int i=1;i<=n;i++){
//				if(cnt[i]==cnt1){
//					cnt[i]--;
//					while(a[i][cnt[i]]==0&&cnt[i]>0){
//						cnt[i]--;
//					}
//				}
//			}
//			cnt1=0;
//			for(int i=1;i<=n;i++){
//				cnt1=max(cnt1,cnt[i]);
//			}
//		}
//	}
//	if(cnt1==0){
//		printf("0");
//		return 0;
//	}
//	if(sum1==m){
//		for(int i=1;i<=n;i++){
//			if(cnt[i]==cnt1){
//				ans=1ll*a[i][0];
//				break;
//			}
//		}
//		for(int i=1;i<=n;i++){
//			if(cnt[i]==cnt1){
//				ans=ans&(1ll*a[i][0]);
//			}
//		}
//		printf("%lld",ans);
//		return 0;
//	}
//	while(cnt1>0){
//		for(int i=1;i<=n;i++){
//			if(cnt[i]==cnt1&&f[i]==1){
//				cnt[i]--;
//				while(a[i][cnt[i]]==0&&cnt[i]>0){
//					cnt[i]--;
//				}
//			}
//			else{
//				f[i]=0;
//			}
//		}
//		for(int i=1;i<=n;i++){
//			if(f[i]==1){
//				cnt1=max(cnt1,cnt[i]);
//			}
//		}
//		sum1=0;
//		while(sum1<m&&cnt1>0){
//			for(int i=1;i<=n;i++){
//				if(cnt[i]==cnt1&&f[i]==1){
//					sum1++;
//				}
//			}
//			if(sum1>=m){
//				break;
//			}
//			if(sum1<m){
//				for(int i=1;i<=n;i++){
//					if(cnt[i]==cnt1&&f[i]==1){
//						cnt[i]--;
//						while(a[i][cnt[i]]==0&&cnt[i]>0){
//							cnt[i]--;
//						}
//					}
//				}
//				cnt1=0;
//				for(int i=1;i<=n;i++){
//					if(f[i]==1){
//						cnt1=max(cnt1,cnt[i]);
//					}
//				}
//			}
//		}
//		if(sum1==m){
//			for(int i=1;i<=n;i++){
//				if(a[i][cnt[i]]==cnt1){
//					ans=1ll*a[i][0];
//					break;
//				}
//			}
//			for(int i=1;i<=n;i++){
//				if(a[i][cnt[i]]==cnt1){
//					ans=ans&(1ll*a[i][0]);
//				}
//			}
//			printf("%lld",ans);
//			return 0;
//		}
//	}
//	for(int i=1;i<=n;i++){
//		if(f[i]==1){
//			ans=1ll*a[i][0];
//			break;
//		}
//	}
//	for(int i=1;i<=n;i++){
//		if(f[i]==1){
//			ans=ans&(1ll*a[i][0]);
//			m--;
//		}
//		if(m==0){
//			printf("%lld",ans);
//			return 0;
//		}
//	}
	return 0;
}
