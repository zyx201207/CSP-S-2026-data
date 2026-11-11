#include<bits/stdc++.h>
using namespace std;
const int N=5e5+5;
int n,m,a[N],ans;
long long sum[N];
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
    scanf("%d %d",&n,&m);
    for(int i=1;i<=n;i++)scanf("%d",&a[i]);
    sort(a+1,a+1+n);
    int l=0;
    for(int i=1;i<=n;i++){
    	sum[i]=sum[i-1]+a[i];
    	while(sum[i]-sum[l]+m<(i-l)*a[i])l++;
    	ans=max(ans,i-l);
	}printf("%d",ans);
	return 0;
}
