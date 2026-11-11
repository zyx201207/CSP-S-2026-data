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
int c,t;
vector<int> g[1000006];
int main(){
	//一定一定要初始化！！！
	freopen("hub.in","r",stdin);
	freopen("hub.out","w",stdout);
	//Oct31==Dec25?
    c=read(),t=read();
    while(t--){
    	int n=read(),k=read();
    	for(int i=1;i<=n;i++) g[i].clear();
    	for(int i=1;i<=n-1;i++) g[i].pb(read());
    	if(k==2){
    		cout<<1<<'\n';
    		continue;
		}
		else cout<<(k+1)/2<<'\n';
	}
	return 0;
}

