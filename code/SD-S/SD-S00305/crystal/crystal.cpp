#include<bits/stdc++.h>
#define int long long
using namespace std;
inline int read(){
	int x=0,f=1;char c=getchar();
	while(!isdigit(c)){if(c=='-') f=-1;c=getchar();}
	while(isdigit(c)) x=(x<<3)+(x<<1)+(c^48),c=getchar();return x*f;
}
const int N=5e5+5;
int n,m,a[N],ans=1,res=1,st=1;
signed main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	n=read(),m=read();
	for(int i=1;i<=n;++i) a[i]=read();
	sort(a+1,a+1+n);
	for(int i=2;i<=n;++i){
		if(a[i]==a[i-1]) res=max(++ans,res);
		else{
			while((i-st)*(a[i]-a[i-1])>m&&ans>0&&st<i)//前指针后移保证后指针能后移 
				m+=a[i-1]-a[st],
				--ans,++st;
			//if((i-st)*(a[i]-a[i-1])<=m)
				m-=(i-st)*(a[i]-a[i-1]),
				res=max(++ans,res);
		}
	}
	cout<<res;
	return 0;
}//Oct31==Dec25?
