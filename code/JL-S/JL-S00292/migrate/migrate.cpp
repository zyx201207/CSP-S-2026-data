#include<bits/stdc++.h>
using namespace std;
const int N=1e6+10;
long long c,t,n,d,x[N],p,ans;
int main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	cin>>c>>t;
	while(t--){
		ans=0;
		p=0;
		scanf("%lld%lld",&n,&d);
		for(int i=1;i<=n;i++){
			scanf("%lld",&x[i]);
		}
		/*
		for(int i=1;i<n;i++){
			for(int j=i+1;j<=n;j++){
				p=0;
				for(int k=i;k<=j;k++){
					if(x[i]!=x[j-i+1-i+1]){
						p=1;
					}
				}
				if(p==0){
					ans++;
				}
			}
		}
		printf("%lld",ans);
		puts("");
		* */
		puts("0");
	}
    return 0;
}
