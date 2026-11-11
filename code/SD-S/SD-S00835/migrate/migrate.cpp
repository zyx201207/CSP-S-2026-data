//migrate 
//将点对分成：相离、相切、相交于两点、相交于更多点
//一个点对 ，有且只有一个“相交于两点”，
//没有 相交于更多点，那么计入答案。 
//而且只需要统计相距小于2d ，剩余的直接用相切的计算即可
#include <bits/stdc++.h>
using namespace std;
const int N=2e6+505;
long long x[N],f[N],p[N],n,d,ans;
int main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	int TT;cin >> TT >> TT;
	while(TT--){
		memset(f,0,sizeof f);
		memset(p,0,sizeof p);
		ans=0;
		cin >> n >> d;
		for(int i=1;i<=n;i++){
			cin >> x[i];
		}
		int l=1,r=1;
		while(l<=n && r<=n){
			while(r+1<=n && x[r+1]-x[l]<=d) r++;
			if(x[r]-x[l]==d) f[r]=f[l]+1;
			l++;
		}
		l=n,r=n;
		while(l>=1 && r>=1){
			while(l-1>=1 && x[r]-x[l-1]<=d) l--;
			if(x[r]-x[l]==d) p[l]=p[r]+1;
			r--;
		}
		for(int i=1;i<=n-1;i++){
			if(f[i+1] && p[i]) ans+=max(f[i+1],p[i]);
		}
		cout << ans << endl;
	}
	return 0;
} 
