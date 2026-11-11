#include<iostream>
using namespace std;
const int N=5e5+100;
int nxt[N];
int nw[N];
int a[N];
int ans[N];
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	int n,m;
	scanf("%d%d",&n,&m);
	for(int i=1;i<=n;i++){
		scanf("%d",&a[i]);
		nxt[i]=i+1;
		nxt[nw[a[i]]]=i;
		nw[a[i]]=i;
	}
	for(int i=1;i<=n;i++){
		for(int j=i;j<=n;j++){
			ans[a[j]]++;
			while(a[nxt[j]]==a[j]){
				j=nxt[j];
			}
		}
	}
	for(int i=1;i<=m;i++){
		printf("%d ",ans[i]);
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}