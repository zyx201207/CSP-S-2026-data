#include<bits/stdc++.h>
#define int long long
using namespace std;
int c,t,n,m,a[1000005];
vector <int> l[5005];
signed main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	scanf("%lld %lld",&c,&t);
	while(t--){
		scanf("%lld %lld",&n,&m);
		for(int i=1;i<=n;i++){
			scanf("%lld",&a[i]);
		}
		if(c==11||c==12){
			int awa=a[2]-a[1];
			//printf("\n%lld %lld %lld ",awa,n,m);
			if(m<2*awa) printf("0\n");
			else{
				int t=m/awa;
				int qwq=t*2-1;
				if(n<=qwq){
					printf("0\n");
				}
				else{
					printf("%lld\n",n-qwq);
				}
			}
		}
		else if(c<=10){
			for(int i=1;i<=n;i++){
				l[i].clear();
			}
			for(int i=1;i<=n;i++){
				for(int j=i;j<=n;j++){
					if(a[j]-a[i]<=m){
						l[j].push_back(i);
					}
				}
			}
			int ans=0;
			for(int i=1;i<=n;i++){
				
				if(l[i].size()>=3){
					int t1=l[i][1];
					int t2=l[i][2];
					//cout<<t1<<" "<<t2<<endl;
					int qwq=l[t2][0];
					int cnt=0;
					for(int j=0;j<l[t1].size();j++){
						if(l[t1][j]==qwq) break;
						cnt++;
					}
					ans+=cnt;
				}
			}
			printf("%d\n",ans);
		}
	}
	return 0;
}
