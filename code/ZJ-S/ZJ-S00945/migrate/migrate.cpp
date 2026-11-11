#include<bits/stdc++.h>
using namespace std;
typedef long long LL;
const int maxn=2000005;
LL t,n,d,a[maxn],f[maxn],ans;
LL read(){
	LL num=0,f=1;char ch=getchar();
	while(!isdigit(ch)){if(ch=='-')f=-f;ch=getchar();}
	while(isdigit(ch))num=num*10+ch-'0',ch=getchar();
	return num*f;
}
int main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	read(),t=read();
	while(t--){
		n=read(),d=read(),ans=0;
		for(int i=1;i<=n;i++)a[i]=read();
		for(int i=1;i<=n;i++)
		for(int j=i;j<=n;j++){
			if(j==i){f[j]=1;continue;}
			f[j]=0;
			for(int k=j-1;a[j]-a[k]<=d && k>=i;k--)if(a[j]-a[k]>=(a[j]-a[i]-1)%d+1)f[j]+=f[k];
			if(f[j]==0)
			  for(int k=j-1;a[j]-a[k]<=d && k;k++)f[j]+=f[k];
			if(f[j]==2)ans++;
//			cout<<i<<" "<<j<<":"<<f[j]<<"\n";
		}
		cout<<ans<<"\n";
	}
	
	return 0;
}