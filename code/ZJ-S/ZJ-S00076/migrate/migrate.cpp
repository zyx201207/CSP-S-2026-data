#include<iostream>
#define int long long
using namespace std;
const int N=2000010;
int t,n,d,x[N],far[N],cnt[N],dis[N],start[N];
inline int read(){
	char c=getchar();
	int num=0,op=1;
	while(c<'0'||c>'9'){
		if(c=='-')
			op=-1;
		c=getchar();
	}
	while(c>='0'&&c<='9')
		num=num*10+c-'0',c=getchar();
	return num*op;
}
signed main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	t=read(),t=read();
	while(t--){
		n=read(),d=read();
		for(int i=1;i<=n;i++)
			x[i]=read();
		for(int i=1;i<=n;i++){
			int l=1,r=n,ans=n+1;
			while(l<=r){
				int mid=l+r>>1;
				if(x[mid]<=x[i]+d)
					l=mid+1,ans=mid;
				else
					r=mid-1;
			}
			far[i]=ans;
		}
		for(int i=1;i<=n+1;i++)
			dis[i]=0x3f3f3f3f;
		dis[1]=0;
		int now=1;
		while(now<n){
			for(int j=now+1;j<=far[now];j++)
				dis[j]=dis[now]+1;
			if(far[now]==now)
				break;
			now=far[now];
		}
		int res=0;
		for(int i=1;i<=n;i++){
			for(int j=i;j<=n+1;j++)
				cnt[j]=0;
			cnt[1]=1,start[0]=i,dis[i]=0;
			int now=i;
//			for(int j=1;j<=n;j++)
//				cout<<start[j]<<' ';
//			cout<<endl;
			for(int j=1;j<=n-i+1;j++){
				if(dis[j]==0x3f3f3f3f)
					break;
				for(int k=j;k<=far[j+i]-i+1;k++)
					if(dis[k]==dis[j]+1)
						cnt[k]+=cnt[j];
			}
//			cout<<i<<endl;
//			for(int j=i;j<=n;j++)
//				cout<<dis[j]<<' ';
//			cout<<endl;
//			for(int j=i;j<=n;j++)
//				cout<<cnt[j]<<' ';
//			cout<<endl;
			for(int j=1;j<=n-i+1;j++)
				if(cnt[j]==2)
					res++;
		}
		cout<<res<<endl;
	}
}
