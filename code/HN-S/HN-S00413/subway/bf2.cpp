#include<bits/stdc++.h>
using namespace std;
namespace io{
	const int f=1<<21;
	char ob[f],ib[f],*dt,*fn,*op=ob;
	#define gh() ((dt==fn&&(fn=(dt=ib)+(fread(ib,1,f,stdin)))),(dt==fn)?EOF:*dt++)
	inline int read(){
		int x=0;
		char ch=gh();
		for(;!isdigit(ch);ch=gh()){}
		for(;isdigit(ch);ch=gh()){x=x*10+ch-'0';}
		return x;
	}
	void flush(){
		fwrite(ob,1,op-ob,stdout);
		op=ob;
	}
	inline void write(unsigned long long x){
//		cout<<x<<"\n";
//		return; 
		int k=0;
		char s[22];
		if(x==0){s[++k]='0';}
		while(x){
			s[++k]=x%10+'0'; 
			x/=10;
		}
		while(k){*op++=s[k--];}
		*op++='\n';
		if(op-ob>=(f-32)){flush();}
	}
}
const int maxn=5e2+5,maxm=5e5+5;
const long long inf=1e18;
int c,n,m,d,q,w[maxm];
vector<pair<int,int>>vt[maxm];//存每个点被经过的地铁线 和距离 
long long f[maxn][maxn]; 
inline void _min(long long&x,long long w){if(x>w){x=w;}}
int main(){
	freopen("subway3.in","r",stdin);
	freopen("subway.out","w",stdout);
	c=io::read(),n=io::read(),m=io::read(),d=io::read(),q=io::read(); 
	for(int i=1;i<=m;i++){w[i]=io::read();} 
	for(int i=1;i<=n;i++){for(int j=1;j<=n;j++){f[i][j]=inf;}}
	for(int i=1;i<=n;i++){
		f[i][i]=0;
		int fn=io::read();
		while(fn--){
			int a=io::read(),t=io::read();
			vt[a].push_back({i,t});
		}
	}
	for(int i=1;i<=m;i++){
		for(const pair<int,int>&j:vt[i]){
			for(const pair<int,int>&k:vt[i]){
				if(j!=k){_min(f[j.first][k.first],j.second+k.second);}
			}
//			cout<<i<<" "<<j.first<<" "<<j.second<<" i j\n"; 
		}
	}
	for(int k=1;k<=n;k++){for(int i=1;i<=n;i++){for(int j=1;j<=n;j++){_min(f[i][j],f[i][k]+f[k][j]);}}}
//	cout<<f[0][0]<<" ??? f\n";
	while(q--){
		int x=io::read(),y=io::read();//题目保证x!=y不用特判 
		long long mini=inf;
		for(const pair<int,int>&j:vt[x]){
			for(const pair<int,int>&k:vt[y]){
				mini=min(mini,f[j.first][k.first]+j.second+k.second);
			}
		}
		io::write(mini+w[x]+w[y]);
	}
	io::flush();
	return 0;
}
/*
思路(预计思考到15:20)
1.注意到n,d很小，w不重要 
2.我可以O(n*n*n)求出地铁线之间的最短路 
3.x到y的路径上至多经过n个点，否则一定不优
4.因为d很小所以可以直接考虑给经过同一个点的多条路线之间建边O(sum(k)/d*d*d=sum(k)*d=1e8)
5.查询时暴力枚举x是从哪个地铁线开始的和y是从哪个地铁线结束的O(q*d*d=1e5*20*20=4e7) 


0 2 5 20 2
4 1 9 2 5
3 1 5 2 7 4 6
3 2 3 3 4 5 7
1 3
1 2
*/
