#include<bits/stdc++.h>
using namespace std;
#define int long long
int n,m,s[200005],k,bi[200005][35],w,cnt,a[200005],ans;
bool cmp(int x,int y){
	return x>y;
}
signed main(void){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	scanf("%lld%lld",&n,&m);
	for(int i=1;i<=n;i++){
		scanf("%lld",&s[i]);
	}
	sort(s+1,s+n+1,cmp);
	int u=s[1];
	while(u){
		u>>=1;
		w++;
	}
	for(int i=1;i<=w;i++){
		for(int j=1;j<=n;j++){
			bi[j][i]=(s[j]>>(i-1))%2;
		}
	}
	for(int i=w;i>=1;i--){
		cnt=0;
		for(int j=1;j<=n;j++){
			if(bi[j][i]) cnt++;
		}
		if(cnt>=m){
		  k=i;
		  break;	
		}    
	}
	cnt=0;
	for(int i=1;i<=n;i++){
		if(bi[i][k]==1){
			cnt++;
			a[cnt]=s[i];
		}
	}
	sort(a+1,a+n+1,cmp);
	ans=a[1];
	for(int i=2;i<=m;i++){
		ans&=a[i];
	}	
	printf("%lld",ans);
}