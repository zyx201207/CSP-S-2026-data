#include<bits/stdc++.h>
using namespace std;
int c,t,n,d,ans,x[2000001],wi[2000001];
int walk(int xx,int yy){
	int res=0;
	if(abs(x[xx]-x[yy])<=d)
		return 1;
	for(int i=xx;i<yy-1;i++){
		if(x[i+1]-x[xx]<=d&&x[i+2]-x[xx]>d)
			xx++;
		else
			break;
	}
	if(abs(x[xx]-x[yy])<=d)
		return 1;
	for(int i=yy;i>xx+1;i--){
		if(x[yy]-x[i-1]<=d&&x[yy]-x[i-2]>d)
			yy--;
		else
			break;
	}
	for(int i=xx+1;i<yy;i++)
		if(x[i]-x[xx]<=d&&x[yy]-x[i]<=d)
			res++;
	return res;
}
int main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	scanf("%d%d",&c,&t);
	for(;t--;){
		ans=0;
		scanf("%d%d",&n,&d);
		for(int i=1;i<=n;i++)
			scanf("%d",&x[i]);
		for(int i=1;i<=n;i++)
			for(int j=i+1;j<=n;j++){
				if(walk(i,j)==2)
					ans++;
			}
		printf("%d\n",ans);
	}
	return 0;
}
