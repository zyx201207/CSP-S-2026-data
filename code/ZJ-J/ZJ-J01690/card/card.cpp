#include<bits/stdc++.h>
using namespace std;
#define int long long
#define FOR(i,a,b) for(int i=a;i<=b;i++)
#define ROF(i,a,b) for(int i=a;i>=b;i--)
#define lowbit(x) ((x)&(-x))
#define lc(x) (x<<1)
#define rc(x) ((x<<1)|1)
#define IOS ios::sync_with_stdio(false),cin.tie(0),cout.tie(0);
typedef long long ll;
const int N=5e5+10;
const int M=3e5+10; 
const int MOD=1e9+7;
const ll INF=4e18;
int n,m,pd[N],da[M],a[M],b[M];
signed main() {
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	cin>>n>>m;
	FOR(i,1,n) {
		cin>>pd[i];
		a[pd[i]]++;
	}
	FOR(i,1,n) {
		FOR(j,1,m) {
			b[j]=a[j];
		}
		FOR(j,i,n) {
			if(b[pd[j]]>=2) {
				int x=pd[j];
				b[pd[j]]--;
				FOR(k,j+1,n) {
					if(pd[k]==x) {
						j=k-1;
						break;
					}
					else {
						b[pd[k]]--;
					}
				}
				//cout<<j<<'\n';
			}
		}
		FOR(j,1,m) {
			if(b[j]>0) {
				da[j]++;
			}
			//cout<<da[j]<<' ';
		}
		//cout<<'\n';
		a[pd[i]]--;
	}
	FOR(i,1,m) {
		cout<<da[i]<<' ';
	}
	return 0;
} 
