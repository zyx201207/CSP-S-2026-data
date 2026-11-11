#include<bits/stdc++.h>
using namespace std;
int n,m,s,ma;
int a[500005];
int b[500005];
int c[500005];
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	scanf("%d%d",&n,&m);
	for(int i=1;i<=n;i++){
		scanf("%d",a+i);
		ma=max(ma,a[i]);
	}
	for(int i=1;i<=n;i++){
		s=0;
		for(int i=1;i<=ma;i++)b[i]=0;
		for(int j=i;j<=n;j++){
			if(b[a[j]]){
				for(int k=1;k<=n;k++){
					if(b[a[k]]>b[a[j]])b[a[k]]=0;
				}
				s=b[a[j]];
			}
			else {
				s++;
				b[a[j]]=s;
			}
		}
		for(int i=1;i<=ma;i++)if(b[i])c[i]++;
	}
	for(int i=1;i<=m;i++)printf("%d ",c[i]);
}
