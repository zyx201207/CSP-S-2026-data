#include<bits/stdc++.h>
#define int long long
#define endl '\n'
using namespace std;
namespace IO{
	char *p1,*p2,buf[100000];
	#define nc() (p1==p2&&(p2=(p1=buf)+fread(buf,1,100000,stdin),p1==p2)?EOF:*p1++)
	template<class T>
	inline void read(T &x){
		int f=1,ch=nc();x=0;
		while(!isdigit(ch)){
			if(ch=='-') f=-f;
			ch=nc();
		}
		while(isdigit(ch)){
			x=(x<<3)+(x<<1)+ch-'0';
			ch=nc();
		}
		x*=f;
	}
	template<class T>
	void write(T x){
		if(x<0) putchar('-'),x=-x;
		if(x>9) write(x/10);
		putchar(x%10+'0');
	}
};
using namespace IO;
constexpr int N=500005;
int n,m,ans,a[N],s[N]; 
signed main(){
	ios::sync_with_stdio(false);
	cin.tie(0),cout.tie(0);
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	read(n),read(m);
	for(int i=1;i<=n;i++){
		read(a[i]);
	}
	sort(a+1,a+1+n);
	for(int i=1;i<=n;i++){
		s[i]=s[i-1]+a[i];
		int l=1,r=i;
		while(l<r){
			int mid=(l+r)>>1;
			if(s[i]-s[mid-1]+m>=(i-mid+1)*a[i]){
				r=mid;
			}else l=mid+1;
		}
		ans=max(ans,i-r+1);
	}
	cout<<ans;
}

