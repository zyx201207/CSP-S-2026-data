#include<bits/stdc++.h>
#define ll long long
#define ull unsigned long long
#define lowbit(x) ((x)&(-x))
using namespace std;
template<typename T>inline void read(T &n);
const int N=5e5+5; 
ll a[N];
unordered_map<ll,ll>mp;//统计特定的数有几个 
int main(){
	ios::sync_with_stdio(0);
//	freopen("debug.in","r",stdin);
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	int n;
	ll m;
	read(n),read(m);
	for (int i=1;i<=n;i++) read(a[i]);
	sort(a+1,a+n+1);//升序排列 
	for (int i=1;i<=n;i++){
		mp[a[i]]++;
	}
	int all=unique(a+1,a+n+1)-(a+1);
//	for (int i=1;i<=all;i++) cerr<<a[i]<<' ';
//	cerr<<'\n';
	ll ans=1;
	//O(n^2)期望得分60
	for (int i=1;i<=all;i++){//钦定a[i]为选定的目标值 
		ll tmp=m,res=0;
		for (int j=i-1;j>=1;j--){
			ll d=a[i]-a[j];
			if (tmp<d) break;
			ll cnt=tmp/d;
			cnt=min(mp[a[j]],cnt);
			tmp-=(d*cnt);
			res+=cnt;
		}
		ans=max(ans,res+mp[a[i]]);
	} 
	cout<<ans;
	return 0;
}
template<typename T>inline void read(T &n){
	n=0;T f=1;
	char c;
	do{
		c=getchar();
		if (c=='-') f=-1;
	}while (c<'0'||c>'9');
	while (c>='0'&&c<='9'){
		n=(n<<1)+(n<<3)+(c^48);
		c=getchar();
	}
	n*=f;
}
/*

#include<bits/stdc++.h>
#define ll long long
#define ull unsigned long long
#define lowbit(x) ((x)&(-x))
using namespace std;
template<typename T>inline void read(T &n);
const int N=5e5+5; 
const ll INF=1e18;
ll a[N];
ll c_sum[N],x_sum[N];
unordered_map<ll,ll>mp;//统计特定的数有几个 
bool check(int k,int i,ll m){
	ll sum=a[i]*(c_sum[i-1]-c_sum[k-1])-(x_sum[i-1]-x_sum[k-1]);
	return (sum<=m);
}
int main(){
	//ios::sync_with_stdio(0);
	freopen("debug.in","r",stdin);
//	freopen("crystal.in","r",stdin);
//	freopen("crystal.out","w",stdout);
	int n,m;
	read(n),read(m);
	for (int i=1;i<=n;i++) read(a[i]);
	a[0]=INF;
	sort(a+1,a+n+1);//升序排列 
	for (int i=1;i<=n;i++){
		mp[a[i]]++;
	}
	int all=unique(a+1,a+n+1)-(a+1);
	//预处理前缀和
	for (int i=1;i<=n;i++){
		c_sum[i]=c_sum[i-1]+mp[a[i]];
		x_sum[i]=x_sum[i-1]+(a[i]*mp[a[i]]);
	} 
	ll ans=mp[a[1]]; 
	//二分找最长合法后缀 
	for (int i=2;i<=all;i++){//钦定a[i]为选定的目标值 
		ll tmp=m,res=0;
		//手写二分
		int l=1,r=i-1,t=-2;
		while (l<=r){
			int mid=(l+r)>>1;
			if (check(mid,i,m)) t=mid,r=mid-1;
			else l=mid+1;
		} 
		if (t==-2){
			ll d=(a[i]-a[i-1]);
			ll cnt=min(mp[a[i-1]],m/d);
			res=cnt+mp[a[i]];
		}else{
			res=c_sum[i]-c_sum[t-1];
			if (t!=1){
				ll sum=a[i]*(c_sum[i-1]-c_sum[t-1])+(x_sum[i-1]-x_sum[t-1]);
				ll cnt=min((m-sum)/(a[i]-a[t-1]),mp[a[t-1]]);
				res+=cnt;
			}
		}
		cerr<<i<<":"<<res<<"\n";
		ans=max(ans,res);
	} 
	cout<<ans;
	return 0;
}
template<typename T>inline void read(T &n){
	n=0;T f=1;
	char c;
	do{
		c=getchar();
		if (c=='-') f=-1;
	}while (c<'0'||c>'9');
	while (c>='0'&&c<='9'){
		n=(n<<1)+(n<<3)+(c^48);
		c=getchar();
	}
	n*=f;
}

*/

