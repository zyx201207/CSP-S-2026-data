#include<cstdio>
#include<algorithm>
#include<cstring>
using namespace std;
int n,m,a[200005],mx,mc,cnt,res[200005],ans;
int main(){
	freopen("and.in","r",stdin);freopen("and.out","w",stdout);
	scanf("%d%d",&n,&m);
	for(int i=0;i<n;i++)scanf("%d",&a[i]),mx=max(mx,a[i]);
	while(mx)mc++,mx>>=1;
	for(int i=mc-1;i>=0;i--){
		memset(res,0,sizeof(res));cnt=0;
		for(int j=0;j<n;j++)if((a[j]>>i&1)&&cnt<m)res[cnt++]=j;
		if(cnt==m)break;
	}
	ans=a[res[0]];
	for(int i=1;i<cnt;i++)ans&=a[res[i]];
	printf("%d",ans);
	return 0;
}

