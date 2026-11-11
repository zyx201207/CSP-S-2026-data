#include<bits/stdc++.h>
#define int long long
using namespace std;
int n,m,a[500005],f[500005],b[500005],cnt,k=1,maxx=1,t;
int read(){
	int ret=0,f=1;char ch=getchar();
	while(!isdigit(ch)){if(ch=='-')f=-f;ch=getchar();}
	while( isdigit(ch))ret=(ret<<3)+(ret<<1)+(ch&15),ch=getchar();
	return ret*f;
}
signed main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	n=read(),t=m=read();
	for(int i=1;i<=n;i++)a[i]=read();
	sort(a+1,a+1+n);
	for(int i=1;i<n;i++)b[i]=a[i+1]-a[i];
	f[1]=1;
	for(int i=2;i<=n;i++){
		cnt=0; 
		while(t-(long long)((f[i-1]-cnt)*b[i-1])<0)cnt++,t=t+a[i-1]-a[k++];
		f[i]=f[i-1]-cnt+1;
		t=t-(long long)((f[i-1]-cnt)*b[i-1]);
		if(t>m)break;
		maxx=max(f[i],maxx); 
//		cout<<maxx<<" "<<t<<"\n"; 
	}
	cout<<maxx; 
	return 0;
}
