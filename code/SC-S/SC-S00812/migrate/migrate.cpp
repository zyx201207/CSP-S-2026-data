#include<bits/stdc++.h>
#define int long long
using namespace std;const int N=2e6+5;
int n,_n,d,_a[N],a[N],pre[N],nxt[N],Cpre[N],Cnxt[N],Spre[N],Ssuf[N];
inline int solve(){
	pre[0]=1,nxt[n+1]=n;
	for(int i=1;i<=n;i++)Cpre[i]=Cnxt[i]=Spre[i]=Ssuf[i]=0;
	for(int i=1;i<=n;i++){
		pre[i]=pre[i-1];
		while(a[i]-a[pre[i]]>d)pre[i]++;
		Cpre[pre[i]]++;
	}
	for(int i=n;i>=1;i--){
		nxt[i]=nxt[i+1];
		while(a[nxt[i]]-a[i]>d)nxt[i]--;
		Cnxt[nxt[i]]++;
	}
	for(int i=1;i<=n;i++)Spre[i]=(nxt[pre[i]]==i)*(Spre[pre[i]]+Cnxt[i]);
	for(int i=n;i>=1;i--)Ssuf[i]=(pre[nxt[i]]==i)*(Ssuf[nxt[i]]+Cpre[i]);
	int ans=0;
	for(int i=1;i<=n;i++)if(i<nxt[i]-1&&nxt[i]<n){
		int L=(pre[pre[nxt[nxt[i]-1]]]==i)*Spre[i]+1,R=0,lim=nxt[i];
		if(i<nxt[i]-2)lim=max(lim,nxt[nxt[i]-2]);
		R+=max(nxt[nxt[i]-1]-lim,0LL);
		if(nxt[nxt[i]]==nxt[nxt[i]-1]&&(i>=nxt[i]-2||nxt[nxt[i]]!=nxt[nxt[i]-2]))R+=Ssuf[nxt[nxt[i]]];
		ans+=L*R;
	}
	return ans;
}
signed main(){
	freopen("migrate.in","r",stdin),freopen("migrate.out","w",stdout);
	ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
	int _c,_T;cin>>_c>>_T;
	while(_T--){
		cin>>_n>>d;int ans=0;
		for(int i=1;i<=_n;i++)cin>>_a[i];
		for(int i=1;i<=_n;i++){
			int j=i;
			while(j+1<=_n&&_a[j+1]-_a[j]<=d)j++;
			n=j-i+1;
			for(int k=i;k<=j;k++)a[k-i+1]=_a[k];
			ans+=solve(),i=j;
		}
		cout<<ans<<"\n";
	}
	return 0;
}