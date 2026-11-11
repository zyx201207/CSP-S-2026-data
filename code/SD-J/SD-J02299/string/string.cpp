#include<bits/stdc++.h>
#define ll long long
#define pb push_back
#define pii pair<int,int>
#define x1 x_1
#define x2 x_2
#define y1 y_1
#define y2 y_2
using namespace std;

long long read(){
	char ch=getchar();
	long long res=0;
	int f=1;
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
struct node{
	char ch;
	int x;
}a[200005];
int main(){
	//一定一定要记得初始化！！！！！
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
    int n=read();
    for(int i=1;i<=n;i++){
    	cin>>a[i].x;
    	cin>>a[i].ch;
	}
	int l=1,r=n;
	int restl=a[1].x,restr=a[n].x;
	ll ans=0;
	while(l<r){
		int k=min(restl,restr);
		if(a[l].ch!=a[r].ch) ans+=k;
		restl-=k;
		restr-=k;
		if(restl==0) l++,restl=a[l].x;
		if(restr==0) r--,restr=a[r].x;
	}
	cout<<ans;
	return 0;
}

