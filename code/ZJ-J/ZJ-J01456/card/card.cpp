#include<bits/stdc++.h>
using namespace std;
const int N=5005,M=3005;
int n,m;
int a[N],q[N],ans[M];
bool st[M];
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	scanf("%d%d",&n,&m);
	for (int i=1;i<=n;i++){
		scanf("%d",&a[i]);
	}
	for (int i=1;i<=n;i++){
		for (int j=1;j<=m;j++){
			st[j]=false;
		}
		for (int j=1;j<=n;j++){
			q[j]=0;
		}
		int r=0;
		for (int j=i;j<=n;j++){
			if (st[a[j]]){
				while (q[r]!=a[j]){
					st[q[r]]=false;
					q[r]=0;
					r--;
				}
			}
			else{
				st[a[j]]=true;
				q[++r]=a[j];
			}
		}
		for (int j=1;j<=r;j++){
			ans[q[j]]++;
		}
	}
	for (int i=1;i<=m;i++){
		printf("%d ",ans[i]);
	}
	return 0;
}