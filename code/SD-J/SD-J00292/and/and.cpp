#include<cstdio>
const int N=2e5+5;
int a[N];
int main(){
	freopen("and.in","r",stdin);
    freopen("and.out","w",stdout);
	int n,m;
	scanf("%d%d",&n,&m);
	for(int i=0;i<n;++i)scanf("%d",&a[i]);
	int ans=0;
	for(int i=29;~i;--i){
		int t=ans|1<<i,c=0;
		for(int j=0;j<n;++j)
		if((a[j]&t)==t)c++;
		if(c>=m)ans=t;
		
	} 
	printf("%d\n",ans);
	return 0;
}
