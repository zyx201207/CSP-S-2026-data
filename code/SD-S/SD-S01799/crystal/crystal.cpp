#include<bits/stdc++.h>
#define FST ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
#define int long long
#define ll long long
#define ull unsigned long long
#define mid(l,r)((l+r)>>1)
//#define ls(x)(x<<1)
//#define rs(x)(x<<1|1)
#define lowbit(x)(x&-x)
using namespace std;
const int maxn=5e5+37;
int n,m;
int a[maxn],s[maxn];
bool cmp(int a,int b){
	return a>b;
}
signed main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	FST;
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	sort(a+1,a+n+1,cmp);
	for(int i=1;i<=n;i++){
		s[i]=s[i-1]+a[i];
	}
	int ans=0;
	for(int i=1;i<=n;i++){
		int l=i,r=n;
		while(l<=r){
			int midd=mid(l,r);
			int sum=a[i]*(midd-i+1)-(s[midd]-s[i-1]);
			if(sum<=m){
				ans=max(ans,midd-i+1);
				l=midd+1;
			}else r=midd-1;
		}
	}
	cout<<ans<<endl;
	return 0;
}

