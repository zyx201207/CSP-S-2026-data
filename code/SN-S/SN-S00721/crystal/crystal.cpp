//准考证号:SN-S00721     姓名:强小轩 
#include<bits/stdc++.h>
#define ll long long
#define ull unsigned long long
#define ldb long double
#define eps 1e-7
const int maxn=5e5+10;
const int maxm=1e5+10;
const int mod1=1e9+7;
const int mod2=998244353;
using namespace std;
typedef pair<int,int> Pii;
ll n,m,a[maxn];
int ans;
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
//	ios::sync_with_stdio(false);
//	cin.tie(0);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	sort(a+1,a+1+n);
	ll sum=0;
	for(int i=1,j=1;j<=n;j++){
		sum+=(j-i)*(a[j]-a[j-1]);
		while(sum>m){
			sum-=a[j]-a[i];
			i++;
		}
		ans=max(ans,j-i+1);
	}
	cout<<ans<<'\n';
	return 0;
} 





















