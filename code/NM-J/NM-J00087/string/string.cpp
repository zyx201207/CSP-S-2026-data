#include<bits/stdc++.h>
using namespace std;

int n,lp[200010];
long long l=0,ans=0;
long long nowip=1,nowipl=0,nowp=1,nowpl=0;
char sp[200010];

int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	scanf("%d",&n);
	for(int i=1;i<=n;i++){
		scanf("%d",&lp[i]);
		scanf(" %c",&sp[i]);
		l+=lp[i];
	}
	for(int i=1;i<=l/2;i++){
		while(nowipl+lp[nowip]<i){
			nowipl+=lp[nowip];
			nowip++;
		}
		while(nowpl+lp[nowp]<=l-i){
			nowpl+=lp[nowp];
			nowp++;
		}
		if(sp[nowip]!=sp[nowp]){
			ans++;
		}
	}
	printf("%lld",ans);
	return 0;
}
