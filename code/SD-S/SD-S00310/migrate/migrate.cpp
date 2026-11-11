#include<bits/stdc++.h>
using namespace std;
inline long long rd(){long long f=1,x=0;char ch=getchar();while(ch<'0'||ch>'9'){if(ch=='-')f=-f;ch=getchar();}while(ch>='0'&&ch<='9'){x=x*10+ch-'0';ch=getchar();}return f*x;}
inline void wt(long long x,int opt){int top=0;char a[105];if(x<0)putchar('-'),x=-x;do{a[++top]=x%10+'0';x/=10;}while(x);for(int i=top;i>=1;i--)putchar(a[i]);if(opt==1)putchar(' ');if(opt==2)putchar('\n');}
int c,t;
int n;
long long d;
long long a[2000005];
int l[2000005];
int f[2000005],g[2000005];
int tnl[2000005],fnl[2000005],mfnl[2000005];
long long ans;
void work(){
	int x=1;
	for(int i=1;i<=n;i++){
		while(x<=i&&a[i]-a[x]>d)x++;
		l[i]=x;
		if(!tnl[x])tnl[x]=i;
		fnl[x]=i;
	//	cout<<l[i]<<' ';
	}
	//cout<<endl;
	for(int i=1;i<=n;i++)mfnl[i]=max(mfnl[i-1],fnl[i]);
	

	for(int i=1;i<=n;i++){
		if(l[i]==i-1)f[i]=f[i-1];
		f[i]++;
	//	cout<<f[i]<<' ';
	}//cout<<endl;
	for(int i=n;i>=1;i--){
		if(l[i]==i-1)g[i]=g[i+1];
		g[i]++;
	}
	for(int i=1;i<=n-3;i++){
		int pos=mfnl[i];//可达的最靠右的位置
		long long pre=f[i];
		int p=pos-1;//这个位置能做出二重点 
		if(p<=i)continue;
	//	cout<<i<<' '<<pos<<' '<<p<<endl;
		int mpos=tnl[p];
		if(l[mpos]==p){
			int pp=fnl[p];
			if(l[p]<i)pre=1;
			long long len=pp-(tnl[p])+1;
		//	cout<<"ilen"<<i<<' '<<pre<<' '<<len<<endl;
			pp++;
			if(l[pp]==pp-1){
				long long lenlen=g[pp];
				len+=lenlen;
			}
			ans+=1ll*pre*len;
		}
	//	cout<<i<<"ans="<<ans<<endl;
	}

	wt(ans,2);
}
void init(){
	for(int i=1;i<=n+1;i++)a[i]=0,l[i]=0,f[i]=0,g[i]=0,fnl[i]=0,mfnl[i]=0,tnl[i]=0;
	ans=0;
}
int main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	c=rd();t=rd();
	while(t--){
		n=rd();d=rd();
		for(int i=1;i<=n;i++)a[i]=rd();
		work();
		init();
	}
}

