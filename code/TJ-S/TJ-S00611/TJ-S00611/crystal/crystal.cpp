#include<cstdio>
#include<algorithm>
template<typename T>bool relax(T &a,const T &b){return a<b?a=b,true:false;}
int n;long long m;
const int maxn=5e5+5;
long long a[maxn];
namespace Force{
	void solve(){
		int ans=1;
		for(int i=1;i<=n;i++){
			long long m0=m;int cnt=1;
			for(int j=i-1;j>=1;j--){
				if(m<std::abs(a[i]-a[j])) break;
				m-=std::abs(a[i]-a[j]),cnt++;
			}
			m=m0,relax(ans,cnt);
		}
		printf("%d\n",ans);
	}
}
namespace Better{
	int s[maxn];
	void solve(){
		for(int i=1;i<=n;i++) s[i]=s[i-1]+(i-1)*std::abs(a[i]-a[i-1]);
		int ans=0;
		for(int i=1;i<=n;i++){
			int l=0,r=i;
			while(l<r){
				int mid=(l+r)>>1;
				if(s[i]-(s[mid]+mid*std::abs(a[i]-a[mid]))<=m) r=mid;
				else l=mid+1;
			}
			relax(ans,i-l);
		}
		printf("%d\n",ans);
	}
}
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	scanf("%d%lld",&n,&m);
	for(int i=1;i<=n;i++) scanf("%lld",&a[i]);
	std::sort(a+1,a+n+1);
	if(n<=5000) Force::solve();
	else Better::solve();
	return 0;
}
