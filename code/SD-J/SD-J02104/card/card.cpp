#include<bits/stdc++.h>
using namespace std;
const int N=555555;
int a[N],bo[N];
int st[N*2],top;
int ans[N],n,m; 
void Main(){
	for(int i=1;i<=n;i++){
		for(int j=i;j<=n;j++){
			if(bo[a[j]])j=bo[a[j]];
			ans[a[j]]++;
		}
	}
}
int main() {
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	scanf("%d%d",&n,&m);
	for(int i=1;i<=n;i++){
		scanf("%d",&a[i]);
		bo[a[i]]=i;
	}
	Main(); 
	for(int i=1;i<=m;i++)printf("%d ",ans[i]);
	return 0;
}
