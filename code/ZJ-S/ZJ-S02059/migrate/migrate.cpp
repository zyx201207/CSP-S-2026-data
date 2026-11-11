#include<bits/stdc++.h>
#define int long long 
#define For(i,a,b) for(int (i)=(a);(i)<=(b);(i)++)
#define Bor(i,a,b) for(int (i)=(b);(i)>=(a);(i)--)
#define ct continue
#define endl '\n'
#define T() int T;cin>>T;while(T--)
using namespace std;
const int N=1e6+5,MOD=1e9,INF=1e18;
int a[N];
signed main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	T(){
		int n,d;cin>>n>>d;
		bool spA=1,spB=0;
		int idx=-1;
		For(i,1,n){
			cin>>a[i];
		}
		if(n==1 or n==2){
			cout<<0;ct;
		}
		For(i,1,n){
			if(a[i]-d<=a[1] and a[i]+d>=a[n]){
				spB=1;
				idx=i;
				break;
			}
		}
		int cha=a[2]-a[1];
		For(i,3,n){
			if(cha!=a[i]-a[i-1]){
				spA=0;break;
			}
		}
		if(spA){
			int step=d/cha;
			int len=2+step;
			cout<<n-len+1<<endl;
		}else if(spB){
			int ans=0;
			For(i,idx+1,n){
				int k=upper_bound(a+1,a+1+n,a[i]-d)-a-1;
//				cout<<k<<" ";
				if(k>idx)ct;
				ans++;
			}
			cout<<ans<<endl;
		}else cout<<0<<endl;
	}
	return 0;
}
