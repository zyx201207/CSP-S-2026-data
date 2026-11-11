#include<bits/stdc++.h>
#define ll long long
#define pii pair<int,int>
#define pb push_back
#define x1 x_1
#define x2 x_2
#define y1 y_1
#define y2 y_2

using namespace std;
long long read(){
	long long res=0;
	int f=1;
	char ch=getchar();
	while(ch<'0'||ch>'9'){
		if(ch=='-') f=-1;
		ch=getchar();
	}
	while(ch>='0'&&ch<='9'){
		res=(res<<3)+(res<<1)+(ch^48);
		ch=getchar();
	}
	return res*f;
}
int c,n,m,d,q;
const int N=5e5+5;
struct node{
	int to,dep,w;
};
//vector<node> v[N][505];
vector<int> g[N];
int w[N];
int t[N][505];
int a[505][505];
int x[100005],y[100005];
int kkk[500005],ttt[500005];
ll tim[500005];
int main(){
	//一定一定要初始化！！！
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	//Oct31==Dec25?
    c=read(),n=read(),m=read(),d=read(),q=read();
    for(int i=1;i<=m;i++) w[i]=read();
    if(n==1){
    	int k=read();
    	for(int i=1;i<=k;i++){
    		kkk[i]=read(),ttt[i]=read();
    		tim[kkk[i]]=ttt[i];
		}
		for(int i=1;i<=q;i++){
			int p=read(),pp=read();
			cout<<tim[p]+tim[pp]+w[p]+w[pp]<<'\n';
		}
		return 0;
	}
    for(int i=1;i<=n;i++){
    	int k=read();
    	for(int j=1;j<=k;j++){
    		a[i][j]=read();
    		t[a[i][j]][i]=read();
    		for(int s:g[a[i][j]]){
    		//	v[a[i][j]][s].pb({a[i][j],t[a[i][j]][]})
			}
		}
	}
	for(int i=1;i<=q;i++){
		int x=read(),y=read();
		cout<<w[x]+w[y]+t[1][1]<<'\n';
	}
	return 0;
}

