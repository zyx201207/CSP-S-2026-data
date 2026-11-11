#include<bits/stdc++.h>
using namespace std;
const int N=2e6+9;
long long c,n,d,x[N],nxt[N],f[N],g[N],h[N],prv[N];
int main(){
#ifndef DEBUG
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
#endif
	int t;
	int id=0;
	cin>>c>>t;
	while(t--){
		id++;
		cin>>n>>d;
		for(int i=1;i<=n;i++){
			cin>>x[i];
		}
		nxt[n+1]=n;
		for(int i=n;i>=1;i--){
			nxt[i]=nxt[i+1];
			while(x[nxt[i]]-x[i]>d){
				nxt[i]--;
			}
		}
		prv[0]=1;
		for(int i=1;i<=n;i++){
			prv[i]=prv[i-1];
			while(x[i]-x[prv[i]]>d){
				prv[i]++;
			}
		}
		for(int i=n;i>=1;i--){
			//if(nxt[i]==n)continue;
			if(nxt[nxt[i]]==nxt[i])continue;
			f[i]=g[i]=h[i]=0;
			for(int j=max(nxt[i]+1,nxt[max(1ll,nxt[i]-2)]+1);j<=nxt[nxt[i]];j++){
				if(prv[j]==nxt[i]-1/*&&prv[nxt[i]-1]==i&&(prv[nxt[i]-2]!=i||prv[nxt[nxt[i]]]==nxt[i]-1)*/){
					g[i]++;
					h[i]++;
				}
				else if(prv[j]==nxt[i]){
					f[i]++;
				}
			}
			if(prv[nxt[nxt[i]]]==nxt[i]-1/*&&prv[nxt[i]-1]==i&&(prv[nxt[i]-2]!=2||prv[nxt[nxt[i]]]==nxt[i]-1)*/){
				//if(nxt[nxt[nxt[i]]]==nxt[nxt[i]]||nxt[nxt[nxt[i]]!=nxt[nxt[nxt[i]]-1]])
				//if(nxt[nxt[nxt[i]-1]]!=nxt[nxt[nxt[i]]]||nxt[nxt[nxt[i]]]==nxt[nxt[i]])
					g[i]+=f[nxt[i]];
			}
			else if(prv[nxt[nxt[i]]]==nxt[i]){
				f[i]+=f[nxt[i]];
				g[i]+=g[nxt[i]];
				int t=nxt[i];
				if(prv[nxt[t]-1]==t-1){
					g[i]-=h[t];
				}
				/*
				for(int j=max(nxt[t]+1,nxt[max(1,nxt[i]-2)]+1);j<=nxt[nxt[i]];j++){
					if(prv[j]==nxt[i]-1*/
			}
		}
		long long ans=0;
		for(int i=1;i<=n;i++){
			ans+=g[i];
#ifdef DEBUG
			if(id==3)cout<<i<<":"<<nxt[i]<<","<<prv[i]<<","<<f[i]<<","<<g[i]<<endl;
#endif
		}
		cout<<ans<<endl;
		for(int i=0;i<=n+1;i++){
			f[i]=g[i]=h[i]=x[i]=nxt[i]=prv[i]=0;
		}
	}
	return 0;
}
