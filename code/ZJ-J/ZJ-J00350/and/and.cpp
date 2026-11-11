#include<bits/stdc++.h>
using namespace std;
int n,m,ans;
int f[20005][20005];
int a[200005];
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	scanf("%d%d",&n,&m);
	for(int i=1;i<=n;i++){
		scanf("%d",a+i);
	}
	for(int i=1;i<=n;i++){
		f[0][i]=f[i][0]=INT_MAX;
		f[i][1]=a[i];
	}
	for(int i=1;i<=n;i++){
		for(int j=1;j<=i&&j<=m;j++){
			if(i==1&&j==1)f[i][j]=a[i];
			else f[i][j]=max(f[i-1][j],f[i-1][j-1]&a[i]);
			
		}
		
	}
	printf("%d",f[n][m]);
}
