#include<bits/stdc++.h>
using namespace std;
long long n,a[500005],f[500005],s[500005],cha[500005];
long long m;
long long ans=0,maxx=0;
void dfs(int x,long long cnt,long long geshu,int i){
	if(cnt>m) return;
	if(cnt<=m){
		ans=max(ans,geshu);
	}
	for(int r=x+1;r<=n;r++){
		if(r==x||(a[i]-a[r])<0) continue;
		dfs(r,1ll*(cnt+(a[i]-a[r])),1ll*(geshu+1),i);
	}
}
int main(){
	freopen("crystal.in","r", stdin);
	freopen("crystal.out","w", stdout);
	scanf("%d%lld",&n,&m);
	int flag=1;
	long long c;
	for(int i=1;i<=n;i++){
		scanf("%lld",&a[i]);
		if(i!=1&&i!=2&&flag==1){
			if(a[i]-a[i-1]!=a[i-1]-a[i-2]) flag=0;
		}
		c=a[i]-a[i-1];
	}
	if(flag){
		printf("%lld",1ll*m/c);
		return 0;
	}
	sort(a+1,a+1+n);
	for(int i=1;i<=n;i++){//选定第i个 
		dfs(0,0,0,i);
		maxx=max(maxx,ans);
		ans=0;
	}
	printf("%lld",maxx);
	return 0;
}
