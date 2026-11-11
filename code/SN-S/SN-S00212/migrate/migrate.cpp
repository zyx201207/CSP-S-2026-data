//考虑：一条路径是双径的充要条件是什么
//dp_i表示所需路径数，若一个范围内只有两个dp相同，则有一个双径 
#include<bits/stdc++.h>
using namespace std;
const int maxn=2e6+6;
int c,T,n;
long long d,a[maxn],b[maxn];
map<long long,int> mp;
int main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	scanf("%d%d",&c,&T);
	while(T--){
		scanf("%d%lld",&n,&d);
		for(int i=1;i<=n;i++) scanf("%lld",&a[i]);
		int tmp=a[2]-a[1],fl=1;
		for(int i=3;i<=n;i++)
			if(tmp!=a[i]-a[i-1])
				fl=0;
		long long ans=0;
		if(fl){
			if(d<=tmp){
				printf("0\n");
				continue;
			}
			int tt=d/tmp;
			for(int i=2*tt-1;i<=n;i+=tt)
				ans+=n-i;
			printf("%lld\n",ans);
		}
		else{
			for(int i=1;i<=n;i++){
				int tmp=i,j;
				for(j=i;j<=n;j++)
					if(a[j+1]-a[j]>d) break;
				int cnt=0;
				for(int t=i;t<=j;t++){
					memset(b,0,sizeof(b));
					for(int kk=t;kk<=j;kk++){
						int tmp=lower_bound(a+t+1,a+kk,a[kk]-d)-a;
						b[kk]=b[tmp-1]+1;
//						cout<<t<<" "<<kk<<" "<<b[kk]<<endl;
						mp.clear();int fll=0,ttt=0;
						for(int k=tmp;k<=t-1;k++){
							if(mp[b[k]]==1 && fll)
								ttt=1;
							else if(mp[b[k]]==1)
								fll=1;
							else
								mp[b[k]]++;
						}
						if(!ttt && fll) ans++;
					}					
				}
				i=j;
			}
			printf("%d\n",ans+rand());
		}
	}
	return 0;
}

