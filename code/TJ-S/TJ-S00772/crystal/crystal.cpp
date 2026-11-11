#include<cstdio>
#include<algorithm>
using namespace std;
const int N=5e5+10;
long long int line[N];
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	long long int n,m;
	scanf("%lld %lld",&n,&m);
	for(int i=1;i<=n;i++){
		scanf("%lld",&line[i]);
	}
	sort(line+1,line+1+n);
	long long int i=1,j=1,cnt=0,ans=0;
	while(i<=j&&i<=n&&j<=n){
		cnt+=(line[j]-line[j-1])*(j-i);
		while(cnt>m){
			ans=max(ans,j-i);
			cnt-=(line[j]-line[i]);
			i++;
		}
		
		j++;
	}
	if(ans==1){
		printf("0");
		return 0;
	}
	printf("%lld",ans);
	
	return 0;
}
