#include<bits/stdc++.h>
using namespace std;
struct node{
	int s;
	int w;
};
int n,m;
node a[200005];
bool cmp(node &a,node &b){
	if(a.w!=b.w) return a.w>b.w;
	return a.s>b.s;
}
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	
	scanf("%d%d",&n,&m);
	for(int i=1;i<=n;i++){
		scanf("%d",&a[i].s);
		a[i].w=0;
		int k1,x=a[i].s;
		for(k1=31;k1>0;k1--){
			if((1<<k1)<x){
				k1*=2;
				break;
			}
		}
		for(int k=k1;k>0;k--){
			if(x>=(1<<k)){
				a[i].w++;
				x-=(1<<k);
			}
		}
	}
	sort(a+1,a+n+1,cmp);
	int ans=a[1].s;
	for(int i=2;i<=m;i++){
		ans=ans&a[i].s;
	}
	printf("%d",ans);
	
	return 0;
}
