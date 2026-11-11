#include <bits/stdc++.h>
#define int long long
using namespace std;
int rd(){
	int w = 0 , f = 1;char ch=getchar();
	while(ch<'0'||ch>'9'){
		if(ch=='-') f = -1;
		ch=getchar();
	}
	while('0'<=ch&&ch<='9') w=(w<<3)+(w<<1)+(ch&15),ch=getchar();
	return w*f;
}
void wt(int x){
	if(x<0) putchar('-'),x=-x;
	if(x>9) wt(x/10);
	putchar(x%10+'0');
}
const int N = 2e6+15;
int c,t,n,d,x[N],l[N],r[N],f[N],g[N],sum[N];
vector <int> s1[N],s2[N];
signed main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	c=rd(),t=rd();
	while(t--){
		for(int i = 0 ; i<=n+10 ; i++) x[i]=l[i]=r[i]=f[i]=g[i]=sum[i]=0,s1[i].clear(),s2[i].clear();
		n=rd(),d=rd();
		for(int i = 1 ; i<=n ; i++) x[i]=rd();
		for(int i = 1 , j = 1 ; i<=n ; i++){
			while(j<i&&x[i]-x[j]>d) ++j;
			s1[l[i]=j].emplace_back(i);
		}
		for(int i = n , j = n ; i ; i--){
			while(j>i&&x[j]-x[i]>d) --j;
			s2[r[i]=j].emplace_back(i);
		}
		for(int i = 1 ; i<=n ; i++){
			f[i]+=s2[i].size();if(!s2[i].size()) continue;
			f[i]+=f[s2[i][0]];
		}
		for(int i = n ; i ; i--){
			g[i]+=s1[i].size();if(!s1[i].size()) continue;
			g[i]+=g[s1[i][(int)s1[i].size()-1]];
		}int ans = 0;
//		for(int i = 1 ; i<=n ; i++) cout<<f[i]<<" "<<g[i]<<"\n";cout<<"\n";
		for(int i = 1 ; i<n ; i++){
			ans+=(f[i+1]-(r[i+1]==i+1)-(r[i]==i+1))*(g[i]-(l[i+1]==i)-(l[i]==i));
//			cout<<(f[i+1]-(r[i+1]==i+1)-(r[i]==i+1))<<" "<<(g[i]-(l[i+1]==i)-(l[i]==i))<<"\n";
		}
		wt(ans),putchar('\n');
	}
	return 0;
}
/*0 1
10 3
0 3 6 7 8 9 10 11 14 17
*/