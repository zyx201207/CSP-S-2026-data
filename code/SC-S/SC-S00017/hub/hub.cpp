#include<bits/stdc++.h> 
using namespace std;
#define int long long
const int N=2e6+5;
int n,k,maxx=0; 
int c,t; 
int cnt=0,head[N],dep[N];
struct ed{
	int from,next,to;
}bian[N*2];
void add(int a,int b){
	bian[++cnt].from=a;
	bian[cnt].to=b;
	bian[cnt].next=head[a];
	head[a]=cnt;	
}
void go(int i,int d,int fa){
	dep[i]=d;
	maxx=max(maxx,d);
	for(int e=head[i];e;e=bian[e].next){
		if(bian[e].to!=fa) go(bian[e].to,d+1,i);
	}
}
signed main(){
	freopen("hub.in","r",stdin);
	freopen("hub.out","w",stdout);
	cin>>c>>t;
	while(t--){
		cnt=0;
		memset(head,0,sizeof(head));
		memset(bian,0,sizeof(bian));
		memset(dep,0,sizeof(dep));
		cin>>n>>k;
		for(int i=1;i<n;i++){
			int a,b;
			cin>>a>>b;
			add(a,b);
			add(b,a);
		}
		go(1,1,0);
		cout<<(maxx+dep[1])/k<<endl;//bu ke yi zong si ling
	}
	
	
	
	return 0;
}
/*
不是不考高数符号吗咋回事啊
我一个没看懂啥意思啊
？？？随机猜测题目含义
qyl你牛大了
居然敢骗我说不用背符号含义
 
让我阅读理解一下
最少条数的最大值最小是吧。。？
 
呃呃呃
全球oi实力上升100倍而我不变
 
*/