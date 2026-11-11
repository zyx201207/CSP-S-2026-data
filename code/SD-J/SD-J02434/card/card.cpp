#include<bits/stdc++.h>
using namespace std;
const int N=5e5+5;
int a[N],n,m,b[N],ans[N],g[N],point=0;
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	scanf("%d",&n);
	scanf("%d",&m);
	for(int i=1;i<=n;i++){
		scanf("%d",&a[i]);
		b[i]=0;
	}
	for(int st=1;st<=n;st++){
		point=0;
		for(int i=st;i<=n;i++){
			if(b[a[i]]>0){
				while(1){
					if(g[point]==a[i]){
						b[g[point]]--,g[point]=0,point--;
						break;
					}else{
						b[g[point]]--,g[point]=0,point--;
					}
				}
			}
			point++;
			g[point]=a[i];
			b[a[i]]++;
		}
		for(int i=1;i<=m;i++){
			ans[i]+=ceil(b[i]*1.0/1e9);
			b[i]=0; 
		}
	}
	for(int i=1;i<=m;i++){
		printf("%d ",ans[i]);
	}
	return 0;
}

