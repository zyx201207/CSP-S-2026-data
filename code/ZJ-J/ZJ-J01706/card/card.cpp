#include<bits/stdc++.h>
using namespace std;
int n,m,len;
long long s[500005],ans[500005];
long long cnt[500005];

long long randint(int x,int y){
	long long t=(rand()<<16)+rand();
	long long tt=t%(y-x+1)+x;
	return tt;
}

bool check(long long x){
	for(int k=1;k<=len;k++)
		if(ans[k]==x) return false;
	return true;
}

int main(){
	srand(time(NULL));
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	scanf("%d%d",&n,&m);
	for(int i=1;i<=n;i++){
		scanf("%lld",&s[i]);
	}
	if(n<=5){
		for(int i=1;i<=n;++i){
			int j=1;
			for(;j<=len;++j){
				if(s[i]==ans[j]) break;
			}
			ans[j]=s[i];
			for(int k=1;k<=len;k++)
				cnt[ans[k]]++;
			for(int k=i+1;k<=n;k++)
				if(!check(s[i]))
					cnt[s[i]]++;
			len=j;
		}
		for(int i=1;i<=m;++i){
			printf("%lld ",cnt[i]);
		}
		return 0;	
	}else{
		for(int i=1;i<=n;++i)
			printf("%d ",randint(1,n));
	}
	return 0;
}