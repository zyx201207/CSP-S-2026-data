#include<bits/stdc++.h>
using namespace std;
int read(){
	int x=0,f=1;
	char ch=getchar();
	while(1){
		if(ch=='-') {
			f=-1;
			ch=getchar();
		}
		else if(ch>='0'&&ch<='9') {
			x=10*x+ch-'0';
			ch=getchar();
		}
		else return x*f;
	} 
}
long long c,n,m,d,q,depart,desti,ans;
vector<long long> a[500005];
vector<long long> t[500005];
long long w[500005],cnt[500005];
long long f[505][505];
int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	c=read();
	n=read();
	m=read();
	d=read();
	q=read();
	for(int i=1;i<=m;i++) w[i]=read();
	for(int i=1;i<=n;i++) {
		int x=read();
		for(int j=1;j<=x;j++) {
			int y;
			int z;
			y=read();
			z=read();
			a[y].push_back(i);
			t[y].push_back(z);
			cnt[y]++;
		}
	}
	
//预处理每条边的权值 （完蛋怎么调不出来了） 
for(int i=1;i<=n;i++) {
	for(int j=1;j<=n;j++) f[i][j]=0x7f7f7f7f7f7f;
}
	for(int i=1;i<=m;i++) {
		if(cnt[i]>1) {
			for(int j=0;j<cnt[i];j++) {
				for(int k=j+1;k<cnt[i];k++) {
				f[a[i][j]][a[i][k]]=min(f[a[i][j]][a[i][k]],t[i][j]+t[i][k]);
			}
			}
			
		}
	}
for(int i=1;i<=n;i++) {
	f[i][i]=0;
}
//floyd
	for(int s=1;s<=n;s++) {
		for(int b=1;b<=n;b++) 
		for(int k=1;k<=n;k++) f[s][b]=min(f[s][b],f[k][s]+f[b][k]);	
	}

	
	for(int i=1;i<=q;i++) {
		ans=0;
		depart=read();
		desti=read();
		ans+=w[depart];
		ans+=w[desti];
		int temp=ans;
		ans=0x7f7f7f7f7f7f;
		for(int i=0;i<cnt[depart];i++)
		for(int j=0;j<cnt[desti];j++) ans=min(ans,temp+f[a[depart][i]][a[desti][j]]+t[depart][i]+t[desti][j]);
		cout<<ans<<endl;
}
	return 0;
}
