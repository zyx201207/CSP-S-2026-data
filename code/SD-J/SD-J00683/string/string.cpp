#include<bits/stdc++.h>
using namespace std;

#define int long long
const int N=3e5+5;
int n;
int a[N];
char c[N];
int ans;

inline int read(){
	int f=1,x=0;char ch=getchar();
	while(ch<'0'||ch>'9'){if(ch=='-')f=-1;ch=getchar();}
	while(ch>='0'&&ch<='9'){x=x*10+ch-'0';ch=getchar();}
	return f*x;
}

signed main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	n=read();
	for(int i=1;i<=n;i++){
		a[i]=read();
		cin>>c[i];
	}
	for(int i=1,j=n;i<j;){
		int len=min(a[i],a[j]);
		a[i]-=len;
		a[j]-=len;
		if(c[i]!=c[j])ans+=len;
		if(!a[i])++i;
		if(!a[j])--j;
	}
	cout<<ans<<endl;
	return 0;
} 
