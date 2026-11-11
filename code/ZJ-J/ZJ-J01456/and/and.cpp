#include<bits/stdc++.h>
using namespace std;
const int N=2e5+5,inf=pow(2,30)-1;
int n,m,ans;
int a[N],two[50],app[50];
bool cmp(int x,int y){
	return x>y;
}
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	scanf("%d%d",&n,&m);
	for (int i=1;i<=n;i++){
		scanf("%d",&a[i]);
	}
	for (int i=0;i<30;i++){
		two[i]=pow(2,i);
	}
	for (int i=1;i<=n;i++){
		int j=a[i];
		for (int k=29;k>=0;k--){
			if (j>=two[k]){
				app[k]++;
				j-=two[k];
			}
		}
	}
	for (int i=1;i<=n;i++){
		int j=a[i];
		for (int k=29;k>=0;k--){
			if (j>=two[k]){
				if (app[k]<m){
					a[i]-=two[k];
				}
				j-=two[k];
			}
		}
	}
	sort(a+1,a+n+1,cmp);
	ans=inf;
	for (int i=1;i<=m;i++){
		ans=ans&a[i];
	}
	printf("%d",ans);
	return 0;
}