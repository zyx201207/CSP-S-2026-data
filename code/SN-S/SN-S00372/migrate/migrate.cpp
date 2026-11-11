//姓名：刘烨 考点：西北工业大学附属中学 学校：西安交通大学附属中学 
#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N=2e6+5;

int c,t,n,d,x[N],ans;
int dis[305][305],num[305][305];

signed main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	scanf("%lld%lld",&c,&t);
	while(t--){
		ans=0;
		scanf("%lld%lld",&n,&d);
		for(int i=1;i<=n;i++) scanf("%lld",&x[i]);
		if(0<=c&&c<=6){
			memset(dis,0x3f,sizeof dis);
			for(int i=1;i<=n;i++) dis[i][i]=0;
			for(int i=1;i<n;i++){
				for(int j=i+1;j<=n;j++){
					if(x[j]-x[i]<=d) dis[i][j]=dis[j][i]=num[i][j]=num[j][i]=1;
				}
			}
			for(int k=1;k<=n;k++){
				for(int i=1;i<=n;i++){
					for(int j=1;j<=n;j++){
						if(dis[i][j]>dis[i][k]+dis[k][j]){
							dis[i][j]=dis[i][k]+dis[k][j];
							num[i][j]=num[i][k]*num[k][j];
						}
						else if(dis[i][j]==dis[i][k]+dis[k][j]){
							num[i][j]+=num[i][k]*num[k][j];
						}
					}
				}
			}
			for(int i=1;i<n;i++){
				for(int j=i+1;j<=n;j++){
					if(num[i][j]==2) ans++;
				}
			}
		}else if(c==11||c==12){
			int delta=x[2]-x[1];
			int a,b;
			a=d/delta;
			b=2*a-1;
			ans=max(0*1LL,n-b);
			if(a==0||a==1) ans=0;
		}else if(c==13||c==14){
			for(int i=1;i<=n;i++){
				int posi;
				int l=i,r=n+1;
				while(l<r){
//					cout<<1;
					int mid=(l+r)/2;
					if(x[mid]-x[i]<=d) l=mid+1;
					else r=mid;
				}
				posi=l-1;
				int j;
				for(j=n;j>=1;j--){
					int posj;
					l=i,r=j;
					while(l<r){
//						cout<<2;
						int mid=(l+r)/2;
						if(x[j]-x[mid]<=d) r=mid;
						else l=mid+1;
					}
					posj=l;
					if(posi-posj==1) ans++;
					else break;
				}
				if(j==n) break;
			}
		}
		printf("%lld\n",ans);
	}
	return 0;
}
