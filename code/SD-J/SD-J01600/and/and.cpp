#include<bits/stdc++.h>
using namespace std;
int n,m,a[200005],f;
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	scanf("%d%d",&n,&m);
	for(int i=1;i<=n;i++){
		scanf("%d",&a[i]);
		if(a[i]!=i-1) f=1;
	}
	if(m==1){
		int maxx=-0x3f3f3f3f;
		for(int i=1;i<=n;i++){
			maxx=max(maxx,a[i]);
		}
		printf("%d",maxx);
		return 0;
	}
	else if(m==n){
		int ans=a[1];
		for(int i=2;i<=n;i++){
			ans=ans&a[i];
		}
		printf("%d",ans);
		return 0;
	}else if(m==2){
		int maxx=-0x3f3f3f3f;
		for(int i=1;i<=n;i++){
			for(int j=i+1;j<=n;j++){
				maxx=max(maxx,a[i]&a[j]);
			}
		}
		return 0;
	}
	if(f==0){
		int ans=a[n];
		for(int i=1;i<=m;i++){
			ans=ans&a[n-(2*i)];
		}
		printf("%d",ans);
	}
	return 0;
} 
