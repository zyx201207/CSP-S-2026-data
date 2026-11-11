#include <bits/stdc++.h>
using namespace std;
int main(){
	freopen("hub.in","r",stdin);
	freopen("hub.out","w",stdout);
	int n,m,ans=1,sum=1;
	scanf("%d%d",&n,&m);
	int a[n+1],k[n+1];
	for(int i=1;i<=n;i++){
		scanf("%d%d",&a[i],&k[i]);
	}
	int mi=1000000,x;
	for(int i=2;i<=n;i++){
		if(a[i]-a[i-1]<mi &&  k[i]!=0){
			mi=a[i]-a[i-1];
			x=i;
		}
	}
	int t=m;
	for(int i=x;i<=n;i++){
		if(m>=0){
			m=m-(a[i]-a[i-1]);
			ans++;
		}
	}
	if(m<0){
		ans--;
	}
	for(int i=1;i<=n;i++){
		if(t>=0){
			t=t-(a[i+1]-a[i]);
			sum++;
		}
	}
	if(t<0){
		sum--;
	}
	printf("%d",max(sum,ans));
	return 0;
}
