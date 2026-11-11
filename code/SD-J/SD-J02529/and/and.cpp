#include<bits/stdc++.h>
using namespace std;
int n,m,a[200010];
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	scanf("%d%d",&n,&m);
	for(int i=1;i<=n;i++) scanf("%d",&a[i]);
	int ma=0;
	if(m==1){
		for(int i=1;i<=n;i++){
			ma=max(ma,a[i]);
		}
		printf("%d",ma);
		return 0;
	}else if(m==n){
		ma=a[1];
		for(int i=2;i<=n;i++){
			ma=ma&a[i];
		}
		printf("%d",ma);
		return 0;
	}else if(m==2){
		ma=a[1];
		for(int i=1;i<=n;i++){
			for(int j=2;j<=n;j++){
				ma=max(ma,a[i]&a[j]);
				cout<<ma<<endl;
			}
		}
		printf("%d",ma);
		return 0;
	}else{
		ma=a[2];
		int x=a[2];
		for(int i=1;i<=n;i++){
			for(int j=1;j<=n;j++){
				if(j==i) continue;
				x=x&a[j];
			}
			ma=max(ma,x);
		}
		printf("%d",ma);
		return 0;
	}
	return 0;
}
