#include<iostream>
using namespace std;
int n,m,a[500005],ans[300005],val[500005];
int pos[300005],en[500005];
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	scanf("%d%d",&n,&m);
	for(int i=1;i<=n;i++) scanf("%d",&a[i]);
	for(int i=n;i>=1;i--){
		if(pos[a[i]]==0){
			pos[a[i]]=i;
			en[i]=i;
		}
		else en[i]=pos[a[i]];
	}
	for(int i=1;i<=n;i++){
		ans[a[i]]+=val[i]+1;
		val[en[i]+1]+=val[i]+1;
	}
	for(int i=1;i<=m;i++){
		printf("%d ",ans[i]); 
	}
	return 0;
} 
