//王浩澜 西安交通大学附属中学 SN-S00516
#include<bits/stdc++.h>
using namespace std;
long long c,t,n,d,x[2000005],dis[2000005],f[2000005],tmp,ans,s[2000005];
long long read(){
	char c;
	long long x=0,f=1;
	c=getchar();
	while(c<'0'||c>'9'){
		if(c=='-')
			f=-1;
		if(c==EOF)
			return 0;
		c=getchar();
	}
	while('0'<=c&&c<='9'){
		x=x*10+(c^48);
		c=getchar();
	}
	return x*f;
}
void check(int u){
//	cout<<"u "<<u<<"\n";
	dis[u]=0,f[u]=1,s[u]=1,s[u-1]=0;
	for(int i=u+1;i<=n;i++){
//		cout<<"  i:"<<i;
		tmp=lower_bound(x+u,x+i,x[i]-d)-x;
//		cout<<" xi-d:"<<x[i]-d;
		if(tmp==0)
			tmp=1;
		dis[i]=dis[tmp]+1;
		int tmp2=upper_bound(dis+tmp+1,dis+i,dis[tmp])-dis-1;
		f[i]=s[tmp2]-s[tmp-1];
		s[i]=s[i-1]+f[i];
		if(f[i]==2)
			ans++;
//		cout<<" tmp:"<<tmp<<" dis:"<<dis[i]<<" tmp2:"<<tmp2<<" f:"<<f[i]<<"\n";
	}
//	cout<<"\n";
}
int main()
{
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	c=read(),t=read();
	while(t--){
		ans=0;
		n=read(),d=read();
//		cout<<n<<" "<<d<<endl<<endl;
		for(int i=1;i<=n;i++)
			x[i]=read();
		x[0]=-1e18;
		for(int i=1;i<=n;i++){
			check(i);
		}
		cout<<ans<<"\n";
//		cout<<"\n"<<"\n"<<"\n"<<"\n"<<"\n"<<"\n";
	}
	return 0;
}
