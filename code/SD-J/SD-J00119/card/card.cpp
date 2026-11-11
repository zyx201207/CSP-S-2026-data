#include<bits/stdc++.h>
using namespace std;
const int N=5e5+10,M=3e5+10;
int a[N],b[N],bb[M],ans[M];
int n,m,t=0;
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	scanf("%d%d",&n,&m);
	for(int i=1;i<=n;i++){
		scanf("%d",&a[i]);
	}
	for(int i=n;i>=1;i--){
		b[i]=bb[a[i]];
		bb[a[i]]=i;
	}
	while(++t<=n){
		for(int i=t;i<=n;i++){
			while(b[i]!=0){
				i=b[i];
			}
			ans[a[i]]++;
		}
	}
	for(int i=1;i<=m;i++){
		printf("%d ",ans[i]);
	}
	return 0;
}

