#include<bits/stdc++.h>
using namespace std;
int n,m,a[210000],ans=1<<30-1;
int ma(int x,int d){
	int t=ans,k=0;
	if(x==m){
		return a[n];
	}
	for(int i=d+1;i<=n-m+x;i++){
		ans&=ma(x+1,i);
		k=max(k,ans);
		ans=t;
	}
	return k;
}
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	scanf("%d%d",&n,&m);
	for(int i=1;i<=n;i++){
		scanf("%d",&a[i]);
	}
	for(int i=1;i<=n-2;i++){
		for(int j=i+1;j<=n-1;j++){
			if(a[j]>a[j+1]){
				swap(a[j],a[j+1]);
			}
		}
	}
	if(m==1){
		printf("%d",a[n]);
		return 0;
	}
	if(m==n){
		for(int i=1;i<=n;i++){
			ans&=a[i];
		}
		printf("%d",ans);
		return 0;
	}
	printf("%d",ma(1,0));
	return 0;
}