#include<bits/stdc++.h>
using namespace std;
int c,t,n,k,ans;
const int N=29;
int u[N],v[N];
int d[N],l[N],cntl,mx;
int main(){
	freopen("hub.in","r",stdin);
	freopen("hub.out","w",stdout);
	scanf("%d%d",&c,&t);
	while(t--){
		scanf("%d%d",&n,&k);
		for(int i=1;i<n;i++)scanf("%d%d",&u[i],&v[i]);
		ans=n;
		for(int i=1;i<(1<<n);i++){
			int cnt=0;
			for(int j=0;j<n;j++)cnt+=(i>>j)&1;
			if(cnt!=k)continue;
			for(int j=1;j<n;j++)
				if((i>>(u[j]-1)&1)&&(i>>(v[j]-1)&1))
					--cnt;
			if(cnt>2)continue;
			cntl=0,mx=0;
			for(int j=1;j<=n;j++){
				d[j]=(i>>(j-1)&1)?0:n;
				if(i>>(j-1)&1)l[++cntl]=j;
			}
			for(int i=1;i<=cntl;i++){
				int s=l[i];
				for(int j=1;j<n;j++){
					if(v[j]==s)swap(u[j],v[j]);
					if(u[j]==s&&d[v[j]]>d[s]+1)
						d[v[j]]=d[s]+1,l[++cntl]=v[j],mx=max(mx,d[v[j]]);
				}
			}
			ans=min(ans,mx);
		}
		printf("%d\n",ans);
	}
}