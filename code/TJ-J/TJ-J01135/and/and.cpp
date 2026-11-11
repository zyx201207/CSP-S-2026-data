#include <cstdio>
#include <algorithm>
const int MAXN=2e5+8;
int a[MAXN];
int n,m;
namespace force{
	template <typename T>
	bool relax(T &a,const T &b){return a<b?a=b,true:false;}
	int count21(int x){
		int ans=0;
		for(int i=0;i<30;i++){
			if((x>>i)%2) ans++;
		}
		return ans;
	}
	const int MAXN=2e5+8;
	int a[MAXN];
	void solve(){
		int ans=0;
		for(int i=1;i<=(1<<n);i++){
			if(count21(i)==m){
				int localans=(1<<30)-1;
				for(int j=0;j<30;j++){
					if((i>>j)%2){
						localans&=a[j+1];
					}
				}
				relax(ans,localans);
			}
		}
		printf("%d\n",ans);
	}
}
namespace other{
	int count21(int x){
		int ans=0;
		for(int i=0;i<30;i++){
			if((x>>i)%2) ans++;
		}
		return ans;
	}
	const int MAXN=2e5+8;
	void solve(){
		std::sort(a+1,a+n+1,[](int i,int j){
			if(count21(i)!=count21(j))return count21(i)>count21(j);
			return i>j;
		});
		int ans=(1<<30)-1;
		for(int i=1;i<=m;i++) ans&=a[i];
		printf("%d\n",ans);
	}
}
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	scanf("%d%d",&n,&m);
	for(int i=1;i<=n;i++) scanf("%d",&a[i]);
	if(n<=20) force::solve();
	else other::solve();
}
