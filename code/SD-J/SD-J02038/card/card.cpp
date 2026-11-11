#include<bits/stdc++.h>
using namespace std;
int n,m,h[300005],s[500005],f,t,c[500005],a[500005];
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		scanf("%d",&a[i]);
	}
	for(int i=1;i<=n;i++){
		memset(h,0,sizeof(h));
		f=0;t=0;
		for(int j=i;j<=n;j++){
			if(h[a[j]]>0&&h[a[j]]<=t&&s[h[a[j]]]==a[j]) t=h[a[j]]-1;
			s[++t]=a[j];
			h[a[j]]=t;
		}
		for(int j=f+1;j<=t;j++){
			c[s[j]]++;
		}
	}
	for(int i=1;i<=m;i++){
		printf("%d ",c[i]);
	}
	return 0;
} 
