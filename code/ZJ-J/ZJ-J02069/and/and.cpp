#include<bits/stdc++.h>
using namespace std;
const int maxn=200005;
int n,m,a[maxn],f[maxn][maxn],ans=0;
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	scanf("%d%d",&n,&m);
	for(int i=0;i<n;i++) scanf("%d",&a[i]);
	f[1][0]=a[0];
	for(int i=0;i<n;i++)
	for(int j=0;j<i;j++){
		f[1][i]=a[i];
		for(int k=1;k<m;k++) f[k+1][i]=max(f[k+1][i],f[k][j]&a[i]);
	}
	for(int i=0;i<n;i++) ans=max(ans,f[m][i]);
	printf("%d",ans);
	return 0;
}