#include<bits/stdc++.h>
#define sc(a); scanf("%lld",&a);
using namespace std;
long long n,m,a[500010],k=0,j=0,mm,ans=0;
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	scanf("%lld%lld",&n,&m);
	for(long long i=1;i<=n;i++)
		scanf("%lld",&a[i]);
	sort(a+1,a+n+1);
	for(long long i=1;i<=n;i++){
		j=i;mm=m;k=1;
		while(mm/k>=(a[j+1]-a[j])&&j<n){
			mm-=(k*(a[j+1]-a[j]));
			j++;k++;
			while(a[j+1]==a[j]&&j<=n){
				j++;k++;
			}
		}
		ans=max(ans,k);
	}
	printf("%lld",ans);
	fclose(stdin);
	fclose(stdout);
	return 0;
}
//I am sb
//5 5 1 2 4 8 9
