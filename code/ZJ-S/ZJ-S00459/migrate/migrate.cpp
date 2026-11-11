#include<bits/stdc++.h>
#define int long long
using namespace std;
int C,T,n,d,a[1114514],nxt[1114514],lst[1114514],pl[1114514],pr[1114514],sl[1114514],sr[1114514],tl[1114514],tr[1114514],ans,dp[5114],dis[5114];
vector<int>vl[1114514],vr[1114514];
inline int read(){
	int x=0,f=1;char ch=getchar();
	for(;ch>'9'||ch<'0';ch=getchar())if(ch=='-')f=-1;
	for(;ch>='0'&&ch<='9';ch=getchar())x=(x<<1)+(x<<3)+(ch^48);
	return x*f;
}
inline void er(int x){
	int l=x,r=n,mid,ans=x;
	for(;l<=r;){
		mid=(l+r)>>1;
		if(a[mid]-a[x]<=d)ans=mid,l=mid+1;
		else r=mid-1;
	}
	nxt[x]=ans;
	l=1,r=x,ans=x;
	for(;l<=r;){
		mid=(l+r)>>1;
		if(a[x]-a[mid]<=d)ans=mid,r=mid-1;
		else l=mid+1;
	}
	lst[x]=ans;
	if(x+1<nxt[x])vl[nxt[x]].push_back(x);
	if(lst[x]<x-1)vr[lst[x]].push_back(x);
}
vector<int>vb;
inline void baoli(){
	for(int i=1;i<=n;i++){
		vb={};
		for(int j=1;j<=n;j++)dis[j]=dp[j]=0;
		dp[i]=1;
		vb.push_back(i);
		for(int j=i;;j=nxt[j]){
			vb.push_back(j+1);
			for(int k=j+1;k<=nxt[j];k++)dis[k]=dis[j]+1;
			if(j==nxt[j])break;
		}
		for(int j=0;j<vb.size()-1;j++){
			for(int k=vb[j];k<(j==vb.size()-1?vb[j]+1:vb[j+1]);k++){
				if(dis[k]==dis[k-1])dp[k]+=dp[k-1];
				if(dp[k]==2)ans++;
				if(j!=vb.size()-1&&nxt[k]>=vb[j+1]){
					dp[vb[j+1]]+=min(dp[k],3ll);
					if(dis[nxt[k]+1]==dis[vb[j+1]])dp[nxt[k]+1]-=min(dp[k],3ll);
				}
			}
		}
	}
	cout<<ans<<'\n';
}
signed main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	C=read();T=read();
	for(;T;T--){
		n=read();d=read();ans=0;
		for(int i=1;i<=n;i++)a[i]=read();
		for(int i=1;i<=n;i++)er(i);
		if(C<=10){
			baoli();
			continue;
		}
		for(int i=1;i<n;i++)if(vl[i+1].size()&&vr[i].size()){
			for(int j:vl[i+1])pl[j]=i;
			for(int j:vr[i])pr[j]=i;
		}
		for(int i=1;i<=n;i++)sl[i]=(pl[i]>0)+sl[i-1],sr[i]=(pr[i]>0)+sr[i-1];
		for(int i=1;i<=n;i++){
			if(!pr[i]){
				int x=lst[i];
//				for(;lst[x]!=x&&!pr[x];x=lst[x]);
				if(pr[x]&&sr[i]-sr[x]==0){
					pr[i]=pr[x];
				}
			}
		}
		for(int i=n;i;i--){
			if(!pl[i]){
				int x=nxt[i];
//				for(;nxt[x]!=x&&!pl[x];x=nxt[x]);
				if(pl[x]&&sl[x-1]-sl[i]==0){
					pl[i]=pl[x];
				}
			}
		}
		for(int i=1;i<=n;i++)tl[pl[i]]++,tr[pr[i]]++;
		for(int i=1;i<=n;i++)ans+=tl[i]*tr[i];
		cout<<ans<<'\n';
		for(int i=1;i<=n;i++)vl[i]=vr[i]={},pl[i]=pr[i]=tl[i]=tr[i]=0;
	}
	return 0;
}
/*
15:25~16:18 think
16:20~17:00 jia le /fn
17:00~17:50 luan gao+bao li
*/