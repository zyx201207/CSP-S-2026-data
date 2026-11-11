#include <bits/stdc++.h>
#define int long long
using namespace std;
int read(){
	int x=0,flg=1;
	char c=getchar();
	while(c<'0'||c>'9'){
		if(c=='-')flg=-1;
		c=getchar();
	}
	while(c>='0'&&c<='9')x=(x<<3)+(x<<1)+(c&15),c=getchar();
	return x*flg;
}
const int N=2000010;
int a[N],lef[N],rig[N];
int cntl[N],cntr[N],vall[N],valr[N];
signed main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	int tes,_;cin>>tes>>_;
	while(_--){
		int n=read(),m=read();
		for(int i=1;i<=n;i++)a[i]=read();
		for(int i=0;i<=n+2;i++)cntl[i]=cntr[i]=vall[i]=valr[i]=0;
		for(int i=1,j=1;i<=n;i++){
			while(j<n&&a[j+1]<=a[i]+m)j++;
			rig[i]=j;
		}
		for(int i=n,j=n;i>=1;i--){
			while(j>1&&a[j-1]>=a[i]-m)j--;
			lef[i]=j;
		}
		int ans=0;
		for(int i=1;i<=n;i++)if(rig[i]>i+1)cntr[rig[i]]++;
		for(int i=1;i<=n;i++)if(lef[i]<i-1)cntl[lef[i]]++;
		for(int i=1;i<=n;i++)if(lef[i]!=i&&rig[lef[i]]>i)valr[lef[i]]++;
		for(int i=1;i<=n;i++)if(rig[i]!=i&&lef[rig[i]]<i)vall[rig[i]]++;
		for(int i=1;i<=n;i++)vall[i]++,valr[i]++;
		for(int i=n;i>=1;i--)if(rig[i]!=i&&lef[rig[i]]==i)valr[i]=valr[rig[i]]+valr[i];
		for(int i=1;i<=n;i++)if(lef[i]!=i&&rig[lef[i]]==i)vall[i]=vall[lef[i]]+vall[i];
		for(int i=1;i<=n;i++)vall[i]--,valr[i]--;
		for(int i=1;i<=n;i++)if(rig[i]!=i&&rig[rig[i]]!=rig[i]&&lef[rig[rig[i]]]==rig[i]-1&&lef[lef[rig[rig[i]]]]==i)ans+=vall[i]*valr[rig[rig[i]]];
		for(int i=1;i<=n;i++)if(rig[i]!=i&&rig[rig[i]]!=rig[i]&&lef[rig[rig[i]]]==rig[i]-1)ans+=valr[rig[rig[i]]];
		for(int i=1;i<=n;i++)if(lef[i]!=i&&lef[lef[i]]!=lef[i]&&rig[lef[lef[i]]]==lef[i]+1)ans+=vall[lef[lef[i]]];
		for(int i=1;i<n;i++)ans+=cntr[i+1]*cntl[i];
		printf("%lld\n",ans);
	}
}
