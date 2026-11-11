using namespace std;
#define int long long
#define foR(i,a,b,c) for(int i=a;i<=b;i+=c)
#define For(i,a,b,c) for(int i=a;i>=b;i-=c)
#define il inline
il void file(){
	freopen("hub.in","r",stdin);
	freopen("hub.out","w",stdout);
}
const int maxn=5e5+5;
int n,m,a[maxn],diff[maxn],pre[maxn];
signed main(){
	file();
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	cin>>n>>m;
	foR(i,1,n,1){
		cin>>a[i];
	}
	return 0;
}


