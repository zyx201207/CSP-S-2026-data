#include <bits/stdc++.h>
using namespace std;
int n,m,a[201000],C[201000],s[201000],ans[201000];
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	scanf("%d%d",&n,&m);
	for(int i=1;i<=n;i++){
		scanf("%d",&a[i]);
	}
	for(int i=1;i<=n;i++){
		for(int j=i;j<=n;j++){
			s[j]=0;
		}
		for(int j=1;j<=m;j++){
			C[j]=0;
		}
		for(int j=i;j<=n;j++){
			int x=j;
			if(C[a[x]]){
				for(int k=C[a[x]];k<=j;k++){
					C[s[k]]=0;
					s[k]=0;		
				}
				C[a[x]]=j;
				s[j]=a[x];
			}
			else{
				s[j]=a[x];
				C[a[x]]=j;
			}
		}
		for(int j=i;j<=n;j++){
			ans[s[j]]++;
		}
	}
	for(int i=1;i<=m;i++){
		printf("%d ",ans[i]);
	}
	return 0;
}
