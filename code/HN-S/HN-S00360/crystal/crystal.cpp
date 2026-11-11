#include<bits/stdc++.h>
#define int long long
#define pii pair<int,int>
#define endl '\n'
using namespace std;
constexpr int mod=998244353;
inline int MOD(int a){return (a%mod+mod)%mod;}
inline int add(int a,int b){return (a+b)%mod;}
inline int red(int a,int b){return (a-b+mod)%mod;}
inline int mul(int a,int b){return a*b%mod;}
constexpr int N=5e5+5;
int n,k,a[N],b[N]; 
void solve(){
	cin>>n>>k;
	for(int i=1;i<=n;i++)cin>>a[i];
	sort(a+1,a+n+1);
	for(int i=1;i<=n;i++)b[i]=b[i-1]+a[i];
	int mx=0;
	for(int i=1;i<=n;i++){
		int l=1,r=i;
		while(l<r){
			int mid=(l+r)/2;
			if(a[i]*(i-mid+1)-(b[i]-b[mid-1])>k)l=mid+1;
			else r=mid;
		}
		mx=max(mx,i-l+1);
	}
	cout<<mx<<endl;
}
signed main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	int T=1;
//	cin>>T;
	while(T--)solve();
	return 0;
}
