#include<bits/stdc++.h>
#define ll long long
using namespace std;
ll read(){
	ll s = 0,w = 1;char ch = getchar();
	while(!isdigit(ch)){if(ch=='-')w = -1;ch = getchar();}
	while(isdigit(ch))s = (s<<1)+(s<<3)+ch-'0',ch = getchar();
	return s*w;
}
const int N = 2e6+5;
int n,tc,T,nt[N],lt[N];
ll x[N],d,f[N][2];
int main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	tc = read();T = read();
	while(T--){
		n = read();d = read();
		for(int i = 1;i<=n;i++)x[i] = read();
		for(int i = 1,j = 1;i<=n;i++){
			while(j<n&&x[j+1]-x[i]<=d)j++;
			nt[i] = j;
		}
		for(int i = n,j = n;i;i--){
			while(j>1&&x[i]-x[j-1]<=d)j--;
			lt[i] = j;
		}
		for(int i = 1;i<=n;i++){
			if(lt[i]<i&&nt[lt[i]]==i){
				f[i][0] = lt[i+1]-lt[i]+f[lt[i]][0];
			}else f[i][0] = 0;
		}
		ll ans = 0;
		for(int i = n,p;i>=1;i--){
			if(nt[i]>i&&lt[nt[i]]==i){
				f[i][1] = nt[i]-nt[i-1]+f[nt[i]][1];
			}else f[i][1] = 0;
			p = nt[nt[i]];
			if(p!=nt[i]&&lt[p]==nt[i]-1&&lt[lt[p]]==i)
				ans+=f[i][0]*f[p][1];
			if(p!=nt[i]&&lt[p]==nt[i]-1)
				ans+=f[p][1];
			p = lt[lt[i]];
			if(p!=lt[i]&&nt[p]==lt[i]+1)
				ans+=f[p][0];
			if(lt[i]!=i&&nt[i]!=i)
				ans+=(ll)(lt[i+1]-lt[i])*(nt[i-1]-max(nt[i-2],i));
		}
		printf("%lld\n",ans);
	}
	return 0;
}

