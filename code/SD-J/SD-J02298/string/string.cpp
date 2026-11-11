#include<bits/stdc++.h>
#define int long long
using namespace std;
//namespace FastIo{template<typename T>void read(T &x){int f=1;char ch=getchar();x=0;while(ch<'0'||ch>'9'){if(ch=='-')f=-1;ch=getchar();}while(ch>='0'&&ch<='9'){x=x*10+ch-'0';ch=getchar();}x=x*f;}template<typename T1,typename ...T2>void read(T1 &x1,T2 &...x2){read(x1);read(x2...);}}using namespace FastIo;

const int N=2e5+5;
int n,ans;
int a[N];
char c[N];

signed main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++){cin>>a[i]>>c[i];}
	int l=1,r=n;
	while(l<=r){
		if(a[l]==0)l++;
		if(a[r]==0)r--;
		if(l>=r)break;
		int x=min(a[l],a[r]);
		if(c[l]==c[r])a[l]-=x,a[r]-=x;
		if(c[l]!=c[r]){ans+=x,a[l]-=x,a[r]-=x;}
	}
	cout<<ans;
}
