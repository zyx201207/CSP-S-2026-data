#include <iostream>
#include <unordered_map>
#include <algorithm>
#define i128 int128
#define int long long
using namespace std;
int c,T;
int n;
long long d;
long long x[2000010];
int f[5010][5010],g[5010][5010];
int pre[5010],pre2[5010][5010],pre3[5010][5010];
unordered_map<long long,int> mp;
signed main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	cin>>c>>T;
	while(T--){
		scanf("%lld%lld",&n,&d);
		for(int i=1;i<=n;i++){
			scanf("%lld",&x[i]);
		}
		if(c<=10){
			long long ans=0;
			for(int i=1;i<=n;i++){
				for(int j=1;j<=n;j++){
					f[i][j]=1;
					g[i][j]=1;
					pre2[i][0]=0;
					if(j<=i) pre2[i][j]=0;
				}
			}
			for(int i=1;i<=n;i++){
				auto tmp=lower_bound(x+1,x+n+1,x[i]-d);
				int pos=tmp-x;
				pre[i]=pos;
			}
			for(int i=1;i<=n;i++){
				mp.clear();
				for(int j=i+1;j<=n;j++){
					pre2[i][j]=pre2[i][pre[j]]+1;
					if(mp.count(pre2[i][j])) mp[pre2[i][j]]=max(mp[pre2[i][j]],j);
					else mp[pre2[i][j]]=j;
				}
				for(int j=i;j<=n;j++){
					pre3[i][j]=mp[pre2[i][j]];
				}
			}
			for(int i=1;i<=n;i++){
				for(int j=1;j<=n;j++){
					if(j<=i) pre3[i][j]=i-1;
				}
			}
			for(int i=1;i<=n;i++){
				for(int j=i+1;j<=n;j++){
					int pos=pre[j];
					f[i][j]=g[i][min(pre3[i][pos],j-1)]-g[i][max(0ll,pos-1ll)];
					f[i][j]=max(f[i][j],1ll);
					if(f[i][j]>=5) f[i][j]=5;
					g[i][j]=g[i][j-1]+f[i][j];
//					cerr<<"i:"<<i<<" j:"<<j<<" f[i][j]:"<<f[i][j]<<" pos:"<<pre[j]<<" with"<<x[j]-d<<"\n";
					if(f[i][j]==2) ans++;
				}
			}
			cout<<ans<<"\n";
		}
		else{
			cout<<"0\n";
		}
	}
	return 0;
}
//0 1
//7 666666666666666663
//-1000000000000000000 -555555555555555558 -111111111111111116 111111111111111105 333333333333333326 555555555555555547 999999999999999989

