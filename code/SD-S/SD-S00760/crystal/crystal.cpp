#include<bits/stdc++.h>
#define int long long
#define fi first
#define se second
#define vint std::vector<int>
#define SZ(x) ((int)(x).size())
#define all(x) (x).begin(),(x).end()
#define debug(...) fprintf(stderr,##__VA_ARGS__)

template<typename T>
void read(T&x){
	x=0;
	int f=1;
	char c=getchar();
	while(c<'0'||c>'9'){
		if(c=='-')f=-1;
		c=getchar();
	}
	while(c>='0'&&c<='9')x=x*10+(c-'0'),c=getchar();
	x*=f;
}
std::stack<char>st;
template<typename T>
void print(T x){
	if(x==0)putchar('0');
	if(x<0)putchar('-'),x=-x;
	while(x)st.push('0'+x%10),x/=10;
	while(SZ(st))putchar(st.top()),st.pop();
}
template<typename T>
void printsp(T x){print(x),putchar(' ');}
template<typename T>
void println(T x){print(x),putchar('\n');}

bool Mbe;

const int maxn=5e5+10;

int n,m,a[maxn],s[maxn],ans;

bool Men;

signed main(){
//	system("fc crystal.out crystal4.ans");return 0;
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	debug("%.6lfMB\n",(&Mbe-&Men)/1048576.0);
	read(n),read(m);
	for(int i=1;i<=n;i++)read(a[i]);
	std::sort(a+1,a+n+1);
	for(int i=1;i<=n;i++)s[i]=s[i-1]+a[i];
	for(int i=1;i<=n;i++){
		int l=1,r=i;
		while(l<=r){
			int mid=(l+r)>>1;
			if((i-mid+1)*a[i]-(s[i]-s[mid-1])<=m)r=mid-1;
			else l=mid+1;
		}
		ans=std::max(ans,i-r);
	}
	println(ans);
	debug("%.6lfms\n",1e3*clock()/CLOCKS_PER_SEC);
}
