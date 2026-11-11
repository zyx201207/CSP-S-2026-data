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
const int N=5e5+5;
ll a[N],s[N];
ll n,m;
int main(){
	//一定一定要初始化！！！
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	//Oct31==Dec25?
    n=read(),m=read();
    for(int i=1;i<=n;i++) a[i]=read();
    sort(a+1,a+n+1);
    for(int i=1;i<=n;i++) s[i]=a[i]+s[i-1];
    ll l=1,r=1;
    ll ans=0;
    for(;r<=n;r++){
    	while(l<=r&&(-s[r-1]+s[l-1])+(r-l)*a[r]>m) l++;
    	ans=max(ans,r-l+1);
	}
	cout<<ans;
	return 0;
}

