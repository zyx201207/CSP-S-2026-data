#include <cstdio>
template <typename T>
bool tense(T &a,const T &b){return a>b?a=b,true:false;}
template <typename T>
bool relax(T &a,const T &b){return a<b?a=b,true:false;}
const int MAXN=2e5+8;
long long a[MAXN];
char c[MAXN];
int n;
namespace force{
	int str[250020],len=0;
	void solve(){
		for(int i=1;i<=n;i++) for(int j=1;j<=a[i];j++)str[++len]=c[i];
		int ans=0;
		for(int i=1;i<=(len>>1);i++) if(str[i]!=str[len-i+1]) ans++;
		printf("%d\n",ans);
	} 
}
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	scanf("%d",&n);
	long long suma=0;
	for(int i=1;i<=n;i++){
		char _;
		scanf("%lld%c%c",&a[i],&_,&c[i]),suma+=a[i];
	}
	force::solve();
	return 0;
}
