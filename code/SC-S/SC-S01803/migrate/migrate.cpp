#include<iostream>
#include<cstdio>
#define ll long long
using namespace std;
ll a[2000005];
int to[2000005];
bool canadd[2000005];
int n,c,t;
ll d;
int main(){
	
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	cin.tie(0);
	cout.tie(0);
	
	cin>>c>>t;
	while(t--){
		scanf("%d%lld",&n,&d);
		for(int i=1;i<=n;i++){
			scanf("%lld",&a[i]);
			canadd[i]=0;
		}
		int faris=1;
		for(int i=1;i<=n;i++){
			for(;faris<=n;faris++){
				if(a[faris]-a[i]>d){
					faris--;
					break;
				}
			}
			if(faris>n) faris=n;
			to[i]=faris;
		}
		int cnt=1;//判断三联(至目前有几个相同的)
		ll ans=0;
		for(int i=n-1;i>0;i--){
			if(to[i]==to[i+1]){
				cnt++;
			}else{
				if(cnt==3){
					canadd[i+1]=canadd[i+2]=canadd[i+3]=1;
				}
				cnt=1;
			}
			if(canadd[to[i]]==1){
				ans++;
			}
		}
		printf("%lld\n",ans);
	}
	
	fclose(stdin);
	fclose(stdout);
	
	return 0;
}
/*


*/