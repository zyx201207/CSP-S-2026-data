#include<bits/stdc++.h> 
using namespace std;
const int N=5e5+5;
long long n,m,a[N],las[N],nxt[N],ans;
unsigned long long sum[N];
bool F;
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	scanf("%lld%lld",&n,&m);
	for(long long i=1;i<=n;i++)
		scanf("%lld",&a[i]);
	sort(a+1,a+n+1);
	if(n==1){printf("1\n");return 0;}
	long long g=a[2]-a[1];
	for(long long i=2;i<=n;i++)
		if(a[i]-a[i-1]!=g){F=true;break;}
	if(!F){
		for(long long i=1;i<=n;i++){
			sum[i]=sum[i-1]+(i-1)*(a[i]-a[i-1]);
			if(sum[i]>m){
				printf("%lld\n",i-1);
				return 0;
			}
		}
		printf("%lld\n",n);
		return 0;
	}
	las[1]=1;
	for(long long i=2;i<=n;i++)
		if(a[i]==a[i-1])las[i]=las[i-1];
		else las[i]=i,nxt[las[i-1]]=i;
	for(long long st=1;st<=n;st++){
		bool f=true;
		sum[las[st]]=0;
		for(long long i=nxt[las[st]];i<=n&&i!=0;i=nxt[i]){
			sum[i]=sum[las[i-1]]+(i-st)*(a[i]-a[i-1]);
			if(sum[i]>m){
				ans=max(i-st,ans);
				f=false;
				break;
			}
		}
		if(sum[las[n]]<=m&&f){
			printf("%lld\n",max(ans,n-st+1));
			return 0;
		}
	}
	printf("%lld\n",ans);
	return 0;
}
