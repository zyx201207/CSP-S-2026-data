#include<bits/stdc++.h>
bool Med;
#define rep(i,j,k) for(int i=(j);(i)<=(k);(i)++)
#define per(i,j,k) for(int i=(j);(i)>=(k);(i)--)
#define i64 long long
#define u64 unsigned long long
#define inf 0x3f3f3f3f
#define inf64 0x3f3f3f3f3f3f3f3fll
namespace Staque{
	template<typename T,typename U>inline bool gmax(T &x,const U &y){return x<y?(x=y,1):0;}
	template<typename T,typename U>inline bool gmin(T &x,const U &y){return x>y?(x=y,1):0;}
	void Freopen(){freopen("crystal.in","r",stdin);freopen("crystal.out","w",stdout);}
}using namespace Staque;
const int N=500005;
int n;
i64 a[N],m,pre[N];
void Init(){}
void testCase(){
	std::cin>>n>>m;
	rep(i,1,n)std::cin>>a[i];
	std::sort(a+1,a+1+n);
	rep(i,1,n)pre[i]=pre[i-1]+a[i];
	int ans=0;
	rep(i,1,n){
		int L=1,R=i,res=i;
		while(L<=R){
			int mid=L+R>>1;
			if(1ll*a[i]*(i-mid+1)-(pre[i]-pre[mid-1])<=m)R=mid-1,res=mid;
			else L=mid+1;
		}
		gmax(ans,i-res+1);
	}
	std::cout<<ans<<"\n";
}
bool Mst;
int main(){
	Freopen();
	std::ios::sync_with_stdio(0),std::cin.tie(0);
	int TC=1,CC;
//	std::cin>>TC;
	while(TC--)testCase();
	fprintf(stderr,"Memory:%.3lfMB\nTime:%.3lfs\n",(&Med-&Mst)/1048576.0,clock()*1.0/CLOCKS_PER_SEC);
	return 0;
}
