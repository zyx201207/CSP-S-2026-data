#include<bits/stdc++.h>
#define int long long
#define raed(x) read(x)
#define Spa putchar(' ')
#define Nxt puts("");
#define Pline puts("--------------")
namespace FastIO{
	int read_x,read_f,write_top;
	int write_st[25];
	char read_char;
	inline int read(int &x){
		x=0;
		read_f=1;
		read_char=getchar();
		while(!isdigit(read_char)){
			if(read_char=='-')read_f=-1;
			read_char=getchar();
		}
		while(isdigit(read_char)){
			x=(x<<1)+(x<<3)+(read_char-'0');
			read_char=getchar();
		}
		return x*=read_f;
	}
	inline int read(){
		read_x=0;
		read_f=1;
		read_char=getchar();
		while(!isdigit(read_char)){
			if(read_char=='-')read_f=-1;
			read_char=getchar();
		}
		while(isdigit(read_char)){
			read_x=(read_x<<1)+(read_x<<3)+(read_char-'0');
			read_char=getchar();
		}
		return read_x*read_f;
	}
	inline void write(int x){
		if(x<0)putchar('-'),x=-x;
		do{
			write_st[++write_top]=x%10;
			x/=10;
		}while(x);
		while(write_top)putchar(write_st[write_top--]+'0');
		return ;
	}
	inline void tomax(int &x,int y){
		if(x<y)x=y;
		return ;
	}
	inline void tomin(int &x,int y){
		if(x>y)x=y;
		return ;
	}
}
using namespace FastIO;
using namespace std;
const int N=2e6+5,inf=0x3f3f3f3f;
int type;

int n,d;
int x[N];
namespace Subtask1{
const int N=5005;
int ans;
int f[N],g[N],pre[N];
void solve(){
	read(n),read(d);
	for(int i=1;i<=n;i++)
		read(x[i]);
//	write()
	ans=0;
	for(int i=1;i<=n;i++){
		f[i]=0;
		for(int j=i+1,now=i;j<=n;j++){
			while(x[j]-x[now]>d)now++;
			if(now==j)f[j]=inf;
			else f[j]=f[now]+1;
//			write(f[j]),Spa;
		}
//		Nxt;
		g[i]=1;
		pre[i-1]=0,pre[i]=1;
		for(int j=i+1,L=i,R=i;j<=n;j++){
			if(f[j]==inf)break;
			while(x[j]-x[L]>d)L++;
			while(R<n&&f[R+1]+1<=f[j])R++;
			//from L to R
			g[j]=min(inf,pre[R]-pre[L-1]);
			pre[j]=pre[j-1]+g[j];
//			write(g[j]),Spa,write(L),Spa,write(R),Nxt;
			if(g[j]==2)ans++;
		}
//		write(ans),Nxt;
	}
	write(ans),Nxt;
}
}
namespace Subtask2{
int ans;
int f[N],g[N];
int pre[N];
void solve(){
	read(n),read(d);
	for(int i=1;i<=n;i++)
		read(x[i]);
	
	for(int i=n;i>=1;i--){
		int r=upper_bound(x+1,x+n+1,x[i]+d)-x-1;
		//from i to r need just one step
		f[i]=r-i+1;
		if(r==i||r==i+1||r==n)continue;
		//r and r-1
		//f[r]-(f[r-1]-1)?
		f[i]+=f[r]-(f[r-1]-1);
	}
	for(int i=1;i<=n;i++){
		int l=lower_bound(x+1,x+n+1,x[i]-d)-x;
		//from l to i need just one step
		g[i]=i-l+1;
		if(l==i||l==i-1||l==1)continue;
		g[i]+=g[l]-(g[l+1]-1);
	}
//	cerr<<f[5]<<' '<<f[4]<<endl;
	for(int i=1;i<=n;i++)
		pre[i]=pre[i-1]+g[i];
	ans=0;
	for(int i=2;i<n-1;i++){
		//can through i and i+1
		//from j,use one step can arrive i and i+1,but not i+2
		//so x_{i+1}-d<=x_j < x_{i+2}-d
		//for i and i+1,can use one step jump to k
		//so x_{i-1}+d<x_k<=x_{i}+d
		//how to promise the distance is shortest?
		//so j can't use a step to k
		//so for a j,there is a limitation that x_k>x_j+d
		//x_j+d>x_{i+1}
		//for a j,we will use it for only one i?Yes
		int l=lower_bound(x+1,x+n+1,x[i+1]-d)-x;
		int r=lower_bound(x+1,x+n+1,x[i+2]-d)-x-1;
		//from l to r 
		for(int j=l;j<=l;j++){
//			if(i==3)cerr<<j<<endl;
			int kl=upper_bound(x+1,x+n+1,x[i-1]+d)-x;
			int kr=upper_bound(x+1,x+n+1,x[i]+d)-x-1;
			if(kl>kr)continue;
			//the previous point of j can't use a step to i
			//so previous point c 
			//x_j-d<=x_{c}<x_{i}-d
			int prev=lower_bound(x+1,x+n+1,x[j]-d)-x;
			//use g[prev]?
			//g[prev]-(g[prev+1]-1);
			int c=1+(prev!=j?g[prev]-(g[prev+1]-1):0);
//			if(i==3)cerr<<kl<<' '<<kr<<endl;
			ans+=c*(kr-kl+1);
			//from kl to kr,
			//the shortest paths are j -> i -> k and j->i+1->k
			//for more steps,is (f[kr]-1)?no
			//maybe from kr-1 is still shortest path
			//so we use f[kr]-(f[kr-1]-1)
//			if(i==3)cerr<<f[kr]-(f[kr-1]-1)<<endl;
			ans+=c*(f[kr]-(f[kr-1]-1));
		}
//		cerr<<i<<' '<<ans<<endl;
	}
	write(ans),Nxt;
}
}
namespace Subtask3{
int D;
void solve(){
	read(n),read(d);
	for(int i=1;i<=n;i++)
		read(x[i]);
	if(n==1){
		puts("0");
		return ;
	}
	D=x[2]-x[1];
	d=d/D*D;
	if(d==0||d==1){
		puts("0");
		return ;
	}
	d=d*2-1;
	write(n-d+1),Nxt;
}
}
signed main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	int t;
	read(type),read(t);
	while(t--){
//		Subtask2::solve();
		if(type<=10)Subtask1::solve();
		else if(type==12||type==12)Subtask3::solve();
	}
}
/*
The brid won't fly back
If there are certainly two paths,there is just a different point between these paths?
if the clusion is right
then we consider a shortest path between u and v
if the path is the unique shortest path between u and v
forall a_{i-1} a_{i+1}
there is just one pos
a_{pos}-a_{i-1}<=d and
a_{i+1}-a_{pos}<=d 
it means x_{a_{i+1}}-d<=x_{pos}<=x_{a_{i-1}}+d
if the path is one of the two shortest pathst between u and v
there is only one i
there are two x_{pos} in  x_{a_{i+1}}-d,x_{a_{i-1}}+d
we choose k for a_{i+1} and the a_{i-1}?
there is just one previous point for one k?no,but legal previous point is continuous
ok a data struct can work
and now we need calcuate for every i
f_i and g_i
f_i means how many j that is on the right of i has only one path from i,including i
g_i means how many j that is on the left of i has only one path from i,including i
how to calcuate f_i?
need we use a data struct again?
the answer is not.
If there is just one step from i to j,the shortest path between i and j is unique
if not,we can only jump to the farthest point 
1 -> 2 -> 4
1 -> 3 -> 4
2 -> 3 -> 5
2 -> 4 -> 5
0 1
5 3
-2 -1 0 1 2
0 1
6 2
1 2 3 4 5 6
d*2-1 
*/
