#include<bits/stdc++.h>
#define int long long
using namespace std;
const int maxn=2e6+5,mod1=1e9+7,mod2=998244353;
int c,t,n,d,a[maxn],b[maxn],f[maxn],g1[maxn],g2[maxn],lst[maxn],stt[maxn],nxt[maxn],s1[maxn],s2[maxn],ans;
void solve(int l,int r){
	int m=0;
//	cout << l << " " << r << "\n" ;
	for(int i=l;i<=r;i++) b[++m]=a[i];
	for(int i=1;i<=m;i++){
		for(int j=1;j<=i;j++){
			if(a[i]-a[j]<=d){
				lst[i]=j;
				break;
			}
		}
	}for(int i=1;i<=m;i++){
		for(int j=i-1;j<=m;j++) f[j]=3e18,g1[j]=s1[j]=g2[j]=s2[j]=nxt[j]=stt[j]=0;
		f[i]=0,g1[i]=s1[i]=g2[i]=s2[i]=1,nxt[i]=stt[i]=i;
		for(int j=i+1;j<=m;j++){
			f[j]=f[max(i,lst[j])]+1,g1[j]=s1[nxt[stt[max(i,lst[j])]]]-s1[max(i,lst[j])-1],s1[j]=s1[j-1]+g1[j],g2[j]=s2[nxt[stt[max(i,lst[j])]]]-s2[max(i,lst[j])-1],s2[j]=s2[j-1]+g2[j];
//			cout << "|" << max(i,lst[j]) << " "  << stt[max(i,lst[j])] ;
			if(g1[j]==2 && g2[j]==2) ans++;
			nxt[max(i,lst[j])];
			if(f[j]==f[j-1]){
				stt[j]=stt[j-1];
				nxt[stt[j]]=j;
			}else{
				stt[j]=nxt[j]=j;
			}
		}
//		for(int j=i;j<=m;j++) cout << "|" << f[j] << " " << g[j] ;
//		cout << "\n" ;
	}
	
}signed main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	cin >> c >> t ;
	while(t--){
		ans=0;
		cin >> n >> d ;
		for(int i=1;i<=n;i++) cin >> a[i] ;
		if(c<11){
			for(int i=1;i<=n;i++){
				int j=i+1;
				while(j<=n && a[j]-a[j-1]<=d) j++;
				solve(i,j-1);
				i=j-1;
			}cout << ans << "\n" ;
		}else if(c<13){
			if(n==1 || d<2*a[2]-2*a[1] || a[n]-a[1]<=d){
				cout << "0\n" ;
				continue;
			}cout << n-d/(a[2]-a[1])*2+1 << "\n" ;
		}
	}return 0;
}
/*
我不会唱《白鸟过河滩》:(
<Name>, keep your determination!
*/