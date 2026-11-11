#include<bits/stdc++.h>
#define int long long
using namespace std;
namespace FastIo{template<typename T>void read(T &x){int f=1;char ch=getchar();x=0;while(ch<'0'||ch>'9'){if(ch=='-')f=-1;ch=getchar();}while(ch>='0'&&ch<='9'){x=x*10+ch-'0';ch=getchar();}x=x*f;}template<typename T1,typename ...T2>void read(T1 &x1,T2 &...x2){read(x1);read(x2...);}}using namespace FastIo;

const int N=2e5+5;
int n,m;
int a[N];
int b[N];

bool cmp(int x,int y){return x>y;}

void cf(int x,int now){
	int ans=0,cnt=0;
	while(x){
		cnt++;
		if(x%2==1)ans++; 
		x/=2;
	}
	b[now]=ans;
}


signed main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	read(n,m);
	for(int i=1;i<=n;i++)read(a[i]);
	sort(a+1,a+n+1,cmp);
	for(int i=1;i<=n;i++)cf(a[i],i);
	if(m==1){
		int ans=0;
		for(int i=1;i<=n;i++)ans=max(ans,b[i]);
		cout<<ans;
	}
	if(m==2){
		int ans=0;
		for(int i=1;i<=n;i++){
			for(int j=1;j<=n;j++){
				if(i==j)continue;
				ans=max(1ll*(a[i]&a[j]),ans);
			}
		}
		cout<<ans;
	}
	if(m==n){
		int ans=a[1];
		for(int i=2;i<=n;i++)ans=(ans&a[i]);
		cout<<ans;
	} 
}

