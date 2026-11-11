#include<cstdio>
#include<algorithm>
int n,m,a[200001],cnt[30],start,ans;
bool cmp(int A,int B){
	for(int i=start;i>=0;i--){
		if((A>>i&1)!=(B>>i&1)) return (A>>i&1)>(B>>i&1);
	}return true;
}int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	std::scanf("%d%d",&n,&m);
	for(int i=1;i<=n;i++){
		std::scanf("%d",&a[i]);
		for(int j=29;j>=0;j--) cnt[j]+=(a[i]>>j&1);
	}for(start=29;cnt[start]<m&&start>0;start--);
	std::sort(a+1,a+n+1,cmp);
	ans=a[1];
	for(int i=2;i<=m;i++) ans&=a[i];
	std::printf("%d\n",ans);
	fclose(stdin);
	fclose(stdout);
	return 0;
}
