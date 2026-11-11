#include<bits/stdc++.h>
#define int long long
using namespace std;
const int maxn=2000005;
int c,t,n,d,x[maxn],ans,R[maxn],L[maxn],sum[maxn];
namespace dhcio{
	inline int read(){
		char ch=getchar();int ret=0,f=1;
		while(ch<'0'||ch>'9'){if(ch=='-') f=-f;ch=getchar();}
		while(ch>='0'&&ch<='9') ret=(ret<<3)+(ret<<1)+(ch&15),ch=getchar();
		return ret*f;
	}
	inline void write(int x){
		if(x<0) x=-x,putchar('-');
		if(x>9) write(x/10);
		putchar('0'+x%10);
	}
}
using namespace dhcio;
void init(){
	ans=0;
	for(int i=1;i<=n;i++) L[i]=R[i]=0,sum[i]=1;
}
bool check(int x,int y){
	vector<int> k1;
	k1.push_back(x);
	int now=x;
	while(now!=y){
		if(R[now]==now) return 0;
		if(R[now]<=y) k1.push_back(R[now]),now=R[now];else k1.push_back(y),now=y;
	}
	now=y;
	vector<int> k2;
	k2.push_back(y);
	while(now!=x){
		if(L[now]>=x) k2.push_back(L[now]),now=L[now];else k2.push_back(x),now=x;
	}
	reverse(k2.begin(),k2.end());
	int cnt=0;
	for(int i=0;i<k1.size();i++){
		if(k1[i]!=k2[i]) cnt++;
		if(abs(k1[i]-k2[i])>1) return 0;
	}
	if(cnt==1) return 1;else return 0;
}
void solve(){
	n=read(),d=read();init();
	for(int i=1;i<=n;i++) x[i]=read();
	int last=1;
	for(int i=1;i<=n;i++){
		while(last<n&&x[last+1]-x[i]<=d) last++;
		R[i]=last;
	}
	last=n;
	for(int i=n;i>=1;i--){
		while(last>1&&x[i]-x[last-1]<=d) last--;
		L[i]=last;
	}
	for(int i=1;i<=n;i++)
	for(int j=i;j<=n;j++){
		if(check(i,j)){
			ans++;
		}
	}
	write(ans),putchar('\n');
}
signed main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	c=read(),t=read();
	while(t--) solve();
	return 0;
}
