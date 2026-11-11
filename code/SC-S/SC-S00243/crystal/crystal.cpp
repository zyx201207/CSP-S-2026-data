#include<bits/stdc++.h>
using namespace std;
int a[500010],v[500010],t[200010];
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	int n,m,s,ans=0,c,sum;
	scanf("%d%d",&n,&m);
	for(int i=1;i<=n;i++){
		scanf("%d",&a[i]);
	}
	for(int i=1;i<=n;i++){
		s=c=sum=0;
		memset(v,0,sizeof(v));
		for(int j=1;j<=n;j++){
			if(a[i]>=a[j])v[++c]=a[i]-a[j];
		}
		sort(v+1,v+c+1);
		for(int j=1;j<=c;j++){
			if(sum>m)break;
			sum+=v[j];
			s++;
		}
		ans=max(ans,s);
	}
	printf("%d",ans);
	return 0;
}
/*
5 5
1 2 4 8 9
*/
/*
5 8
-3 -1 2 2 7
*/