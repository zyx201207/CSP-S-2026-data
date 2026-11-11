#include<bits/stdc++.h>
using namespace std;
long long n,a[1000010],ans,c,T,d,mi[10000010];//mi bushu
long long mp[10000010];//geshu
map<long long,long long> maapp;
bool f[1000010];
int main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	scanf("%lld %lld",&c,&T);
	while(T--){
		ans=0;
		scanf("%lld %lld",&n,&d);

		for(int i=1;i<=n;i++){
			scanf("%lld",&a[i]);
		}
		for(long long l=1;l<n;l++){
			maapp.clear();
			maapp[1]=0;
			mi[l]=0;
			mp[l]=1;
		//	cout<<l<<":::::::"<<endl;
			long long ll=l;
			for(long long r=l+1;r<=n;r++){ 
				while(a[r]-a[ll]>d){
				//	cout<<ll<<" "<<maapp[mp[ll]]+1<<endl;
					maapp[mp[ll]]++;
					ll++;
				//	cout<<1;
				}
				if(ll==r){
					break;
				}
				long long k=mp[ll],now=ll+1;
				while(now<r && mi[now]==mi[ll]){
					k+=mp[now];
					now++;
				//	cout<<2;
				}
				mi[r]=mi[ll]+1;
				mp[r]=k;
				ans+=maapp[k-1];
			}
			for(int i=l;i<=n;i++){
				//cout<<i<<"-----"<<mp[i]<<endl;
			}
		}
		printf("%lld",ans);
	}
	return 0;
}

