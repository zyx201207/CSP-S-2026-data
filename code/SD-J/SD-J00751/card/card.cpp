#include<bits/stdc++.h>
using namespace std;
const int N=5e5+10,M=3e5+10;
int n,m;
int a[N];
int p[N];
int cnt[M];
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	scanf("%d%d",&n,&m);
	for(int i=1;i<=n;i++){
		scanf("%d",&a[i]);
	}
	for(int i=1;i<=n;i++){
		memset(p,0,sizeof(p));
		for(int j=i;j<=n;j++){
			for(int k=i;k<=n;k++){
				if(a[j]==p[k]){
					for(int l=k;l<=n;l++){
						p[l]=0;
					}
				}
			}
			p[j]=a[j];
		}
		for(int j=i;j<=n;j++){
			cnt[p[j]]++;
		}
	}
	for(int i=1;i<=m;i++){
		printf("%d ",cnt[i]);
	}
	return 0;
} 
