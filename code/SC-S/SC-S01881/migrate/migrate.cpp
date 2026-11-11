#include<bits/stdc++.h>
using namespace std;
long long mapp[2000005];
bool mapp1[2000005];
int c,t,n,d,lastt,cnt1,cnt2,ans;
int main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	scanf("%d %d",&c,&t);
	for(int i=0;i<t;i++){
		scanf("%lld %lld",&n,&d);
		for(int j=0;j<n;j++)
			scanf("%lld",&mapp[i]);
		lastt=mapp[0];
		for(int j=1;j<n;j++){
			if(mapp[j]-lastt>d){
				if(!mapp1[j]){
					cnt1++;
					mapp1[j-1]=1;
					lastt=mapp[j-1];
				}
				else break;
			}
		}
		lastt=mapp[n-1];
		for(int j=n-2;j>=0;j--){
			if(lastt-mapp[j]>d){
				if(!mapp1[j]){
					cnt2++;
					mapp1[j+1]=1;
					lastt=mapp[j+1];
				}
				else break;
			}
		}
		if(cnt1==cnt2) ans++;
		printf("%lld\n",ans);
	}
	return 0;
} 