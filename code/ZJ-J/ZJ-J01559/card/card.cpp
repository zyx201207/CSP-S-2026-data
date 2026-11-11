#include<bits/stdc++.h>
using namespace std;
int a[500005],s[500005];
int w[500005];
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	int n,m;
	scanf("%d%d",&n,&m);
	for(int i=1;i<=n;i++){
		scanf("%d",&a[i]);
		w[a[i]]=i;
	}
	for(int i=1;i<=n;i++){
		int j=i;
		while(j<=n){
			s[a[j]]++;
			if(w[a[j]]!=j){
				j=w[a[j]]+1;
			}else{
				j++;
			}
		}
	}
	for(int i=1;i<=m;i++){
		printf("%d ",s[i]);
	}
	return 0;
}

