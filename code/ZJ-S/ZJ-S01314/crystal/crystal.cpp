#include<bits/stdc++.h>
using namespace std;
typedef long long LL;
const int N=5e5+5;
int n,j,ans=0;//j为当前最左可以使用的水晶 
LL m,a[N],cur=0;//cur为当前使用的操作数 
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	scanf("%d %lld",&n,&m);
	for(int i=1;i<=n;i++)
		scanf("%lld",a+i);
	sort(a+1,a+n+1);
	j=n-1;
	for(int i=n;i>=1;i--){
		while(j>=1&&cur+a[i]-a[j]<=m){
			cur+=a[i]-a[j];
			j--;
		}
		ans=max(ans,i-j);
		cur=cur-(a[i]-a[i-1])*(i-j-1);
		if(j<1)
			break;
	}
	printf("%d",ans);
	fclose(stdin);
	fclose(stdout);
	return 0;
} 
