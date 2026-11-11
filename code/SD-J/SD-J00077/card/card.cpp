#include<bits/stdc++.h>
using namespace std;
int n,m;
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	scanf("%d%d",&n,&m);
	vector<int> a(n+1),ans(m+1),ne(n+1),pr(m+1);
	for(int i=1;i<=n;i++){
		scanf("%d",&a[i]);
	}
	for(int i=1;i<=n;i++){
		if(pr[a[i]]!=0){
			ne[pr[a[i]]]=i;
		}
		pr[a[i]]=i;
	}
	for(int i=1;i<=n;i++){
		for(int j=i;j<=n;j++){
			if(ne[j]!=0){
				j=ne[j]-1;
			}
			else{
				ans[a[j]]++;
			}
		}
	}
	for(int i=1;i<=m;i++){
		printf("%d ",ans[i]);
	}
	return 0;
}
