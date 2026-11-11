#include<cstdio>
using namespace std;
int n,m,a,cnt[300005];
int main(){
	freopen("card.in","r",stdin);freopen("card.out","w",stdout);
	scanf("%d%d",&n,&m);
	for(int i=0;i<n;i++){
		scanf("%d",&a);
		for(int i=a;i<=m;i++)cnt[i-1]++;
	}
	for(int i=0;i<m;i++)printf("%d ",cnt[i]);
	return 0;
}

