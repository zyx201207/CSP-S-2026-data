#include <bits/stdc++.h>
using namespace std;
#define int long long
#define For(i,a,b) for(int i=a;i<=b;i++)
#define foR(i,a,b) for(int i=a;i>=b;i--)

const int maxn=2e6+6;
int c,t;
int n,d,x[maxn],q[maxn][25],r[maxn],s[maxn];
int bfdp[306],bfdp2[306];

namespace BF{
	void sol(){
		int ans=0;
		For(i,1,n){
			//cout<<i<<'\n';
			For(j,1,n){
				bfdp[j]=maxn;
				bfdp2[j]=0;
			}
			bfdp2[i]=1;
			bfdp[i]=0;
			For(j,i+1,n){
				for(int k=j-1;x[j]-x[k]<=d&&k>=i;k--){
					if(bfdp[k]+1<bfdp[j]){
						bfdp[j]=bfdp[k]+1;
						bfdp2[j]=bfdp2[k];
					}
					else if(bfdp[k]+1==bfdp[j]){
						bfdp2[j]+=bfdp2[k];
					}
					//cout<<j<<' '<<k<<' '<<bfdp2[j]<<'\n';
				}
			}
			For(j,i+1,n){
				if(bfdp2[j]==2)ans++;
			}
		}
		cout<<ans<<'\n';
	}
}

signed main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	cin>>c>>t;
	For(_i,1,t){
		cin>>n>>d;
		For(i,1,n)cin>>x[i];
		BF::sol();
	}
	return 0;
}

