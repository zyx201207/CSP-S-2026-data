#include<bits/stdc++.h>
#define int long long
using namespace std;
int n,d,x[2000005],lr[2000005],ll[2000005],sl[2000005],sr[2000005];
int solvel(int x){
	if(sl[x]!=-712)return sl[x];
	//if(lr[x-1]>=lr[x]-1)return sl[x]=0;
	//if(ll[x]==x)return sl[x]=0;
	int LL=ll[x],RR=ll[x+1]-1;
	if(LL>RR)return sl[x]=0;
	sl[x]=RR-LL+1;
	sl[x]+=solvel(LL);
	return sl[x];
}
int solver(int x){
	if(sr[x]!=-712)return sr[x];
	int LL=lr[x-1]+1,RR=lr[x];
	if(LL>RR)return sr[x]=0;
	sr[x]=RR-LL+1;
	sr[x]+=solver(RR);
	return sr[x];
}
signed main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	int c,t;
	cin>>c>>t;
	for(int I=0;I<t;I++){
		cin>>n>>d;
		for(int i=1;i<=n;i++)
			cin>>x[i];
		lr[0]=1;
		for(int i=1;i<=n;i++){
			lr[i]=lr[i-1];
			for(;lr[i]<=n&&(__int128)x[lr[i]]-x[i]<=d;lr[i]++);
			lr[i]--;
		}
		ll[n+1]=n;
		for(int i=n;i>=1;i--){
			ll[i]=ll[i+1];
			for(;ll[i]>=1&&(__int128)x[i]-x[ll[i]]<=d;ll[i]--);
			ll[i]++;
		}
		for(int i=1;i<=n;i++)
			sl[i]=sr[i]=-712;
		int res=0;
		for(int i=1;i<=n;i++){
			int r=i;
			while(lr[r]!=r)r=lr[r];
			if(r==i||r==i+1||r==i+2)continue;
			for(int j=i;j<=r;j++){
				if(lr[j]<=j+1)continue;
				int LL=lr[lr[j]-2]+1,RR=lr[lr[j]-1];
				//res+=RR-LL+1;
				if(RR-LL+1<=0)continue;
				int LC=1,RC=0;
				if(lr[j-1]<lr[j]-1)LC=solvel(j)+1;
				if(RR==lr[lr[j]])RC=solver(RR);
				//cerr<<j<<' '<<LC<<' '<<RC<<' '<<LL<<' '<<RR<<'\n';
				res+=LC*(RR-LL+1);
				res+=LC*RC;
			}
			i=r;
		}
		cout<<res<<'\n';
		//cerr<<solvel(2)<<'\n';
	}
	return 0;
}