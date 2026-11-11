#include<bits/stdc++.h>
using namespace std;
int n,m,a[500005],s[300005],j[500005],y[500005],cnt[300005];
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	scanf("%d%d",&n,&m);
	for(int i=1;i<=n;i++){
		scanf("%d",&a[i]);
		s[a[i]]=i;
		cnt[a[i]]++;
	}
	for(int i=1;i<=m;i++){
		int k=s[i],b=cnt[i];
		while(s[a[k]]!=n){
			j[a[k]]+=b;
			k=s[a[k]]+1;
		}
	}
	j[a[n]]=n;
	for(int i=1;i<=m;i++){
		printf("%d ",j[i]);
	}
	return 0;
} 