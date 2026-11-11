#include<iostream>
#include<cstdio>
#include<vector>
#include<algorithm>
#define re register
//#define int long long
using namespace std;
inline int read(){
	int x=0,f=1;
	char ch=getchar();
	while(ch>'9'||ch<'0'){
		if(ch=='-') f=-1;
		ch=getchar();
	}
	while(ch>='0'&&ch<='9'){
		x=(x<<3)+(x<<1)+(ch^48);
		ch=getchar();
	}
	return f*x;
}
void write(int x){
	if(x<0){
		putchar('-');
		x=-x;
	}
	if(x>9) write(x/10);
	putchar('0'+x%10);
}
int n,m,d,q,c,w[200005],a,b;
signed main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	cin>>c>>n>>m>>d>>q;
	for(int i=1;i<=m;i++)cin>>w[i];
	int k;
	for(int i=1;i<=n;i++){
		cin>>k;
		for(int j=1;j<=k;j++)
			cin>>a>>b;
	}
	for(int i=1;i<=q;i++){
		int st,en;
		cin>>st>>en;
		cout<<w[st]+w[en]+4*b<<endl;
	}
	return 0;
}

