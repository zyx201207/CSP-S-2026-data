#include<iostream>
#include<vector>
#include<cstring>
using namespace std;
int tc,t,n,m,sr1,sr2,ffa[1000010],f1[1000010],f2[1000010],dp[1000010][3],d,dd,fz,fd1[1000010],fd2[1000010];
vector<int> b[1000010];
void ycl1(int k,int fa){
	ffa[k]=fa;
	dp[k][0]=1;
	dp[k][1]=0;
	dp[k][2]=0;
	for(auto i:b[k]){
		if(i==fa)
			continue;
		ycl1(i,k);
		if(dp[i][0]+1>dp[k][0]){
			dp[k][1]=dp[k][0];
			dp[k][0]=dp[i][0]+1;
			dp[k][2]=i;
		}
		else if(dp[i][0]+1>dp[k][1])
			dp[k][1]=dp[i][0]+1;
		f1[k]+=f1[i];
	}
	if(dp[k][0]>d)
		f1[k]++;
}
void ycl2(int k,int fa){
	int fkz=f1[k]-(dp[k][0]>d);
	for(auto i:b[k]){
		if(i==fa)	
			continue;
		if(d==1 && i==7)
			cerr<<"";
		int fdp=dp[k][2]!=i?dp[k][0]:dp[k][1];
		if(fz+1>dp[i][0]){
			dp[i][1]=dp[i][0];
			dp[i][0]=fz+1;
			dp[i][2]=k;
		}
		else if(fz+1>dp[i][1])
			dp[i][1]=fz+1;
		f2[i]=fkz+f2[k]-f1[i];
		if(dp[i][2]!=i && dp[i][0]>d || dp[i][1]>d)
			f2[i]++;
		ycl2(i,k);
	}
}
void ycl3(int k,int fa,int l){
	if(ffa[k]==fa)
		fd2[k]=min(fd2[k],fz);
	else
		fd1[fa]=min(fd1[fa],fz);
	if(l>d)
		return;
	int kdp[3]={1,0,0};
	for(auto i:b[k]){
		if(i==fa)
			continue;
		int fdp=dp[i][2]!=k?dp[i][0]:dp[i][1];
		if(fz+1>kdp[0]){
			kdp[1]=kdp[0];
			kdp[0]=fz+1;
			kdp[2]=k;
		}
		else if(fz+1>kdp[1])
			kdp[1]=fz+1;
	}
	for(auto i:b[k]){
		if(i==fa)
			continue;
		ycl3(i,k,max(l,kdp[2]!=i?kdp[0]:kdp[1])+1);
	}
}
int main(){
	freopen("hub.in","r",stdin);
	freopen("hub.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin>>tc>>t;
	while(t--){
		cin>>n>>m;
		for(int i=1;i<n;i++){
			cin>>sr1>>sr2;
			b[sr1].push_back(sr2);
			b[sr2].push_back(sr1);
		}
		d=0;
		for(int i=1<<19;i;i>>=1){
			d+=i;
			memset(f1+1,0,4*n);
			memset(f2+1,0,4*n);
			memset(fd1+1,0x1f,4*n);
			memset(fd2+1,0x1f,4*n);
			ycl1(1,0);
			ycl2(1,0);
			for(int i=1;i<=n;i++){
				fz=max(1,f2[i]);
				ycl3(i,ffa[i],2);
				fz=max(1,f1[i]);
				ycl3(ffa[i],i,2);
			}
			dd=1e9;
			for(int i=2;i<=n;i++){
				dd=min(dd,fd2[i]+fd1[i]);
			}
			if(dd<=m)
				d-=i;
		}
		d++;
		cout<<d<<'\n';
		for(int i=1;i<=n;i++)
			b[i].clear();
	}
}
