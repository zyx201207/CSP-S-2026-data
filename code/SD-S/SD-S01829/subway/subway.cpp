#include<bits/stdc++.h>
#define int long long
using namespace std;
int c,n,m,d,q,w[500100],k[510],a[510][30],t[510][30],x,y,ans;
bool fa=1,fb=1,f[510],ff1[500100];
int T=0;
int u[510][510],num[510][510],len[510],ansA=0,ansB=0;
int to[500100][20];
bool sw[510][2];
int msw=0;
int nummm[510][2];
void dfsA(int now,int sum){
//	cout<<":"<<sum<<" "<<now<<endl;
	if(now==y){
		if(ansA==0){
			ansA=sum;
		}else ansA=min(sum,ansA);
		return ;
	}else if(ansA!=0&&sum>=ansA) return ;
	for(int i=1;i<=len[now];i++){
		if(f[u[now][i]]) continue;
		f[u[now][i]]=1;
		dfsA(u[now][i],sum+num[now][u[now][i]]);
		f[u[now][i]]=0;
	}
}
void dfsB(int now,int sum){
	if(now==y){
		if(ansB==0){
			ansB=sum;
		}else ansB=min(sum,ansB);
		return ;
	}else if(ansB!=0&&sum>=ansB) return ;
	for(int i=1;i<=to[now][0];i++){
		for(int j=1;j<=a[i][k[i]];j++){
			if(f[a[i][j]]) continue;
			f[a[i][j]]=1;
			dfsB(a[i][j],sum+1);
			f[a[i][j]]=0;
		}
	}
}
signed main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	cin>>c>>n>>m>>d>>q;
	for(int i=1;i<=m;i++) cin>>w[i];
	for(int i=1;i<=n;i++){
		cin>>k[i];
		if(k[i]>2) fa=0;
		for(int j=1;j<=k[i];j++){
			cin>>a[i][j]>>t[i][j];
			if(T==0) T=t[i][j];
			else if(T!=t[i][j]) fb=0;
		}
	}
	if(n<=2){
		for(int i=1;i<=n;i++){
			for(int j=1;j<=k[i];j++){
				to[a[i][j]][0]++;
				to[a[i][j]][i]=t[i][j];
				sw[a[i][j]][i]=1;
				nummm[a[i][j]]+=t[i][j];
				if(sw[a[i][j]][1]&&sw[a[i][j]][2]){
					if(msw==0) msw=nummm[a[i][j]];
					else msw=min(msw,nummm[a[i][j]]);
				}
			}
		}
		while(q--){
			cin>>x>>y;
			int ans=999999999;
			if(sw[x][1]&&sw[y][1]) ans=min(ans,to[x][1]+to[y][1]);
			if(sw[x][2]&&sw[y][2]) ans=min(ans,to[x][2]+to[y][2]);
			if(sw[x][1]&&sw[y][2]) ans=min(ans,to[x][1]+to[y][2]+msw);
			if(sw[x][2]&&sw[y][1]) ans=min(ans,to[x][2]+to[y][1]+msw);
			cout<<w[x]+w[y]+ans<<endl;
		}
	}
	if(fa){
		for(int i=1;i<=n;i++){
			if(k[i]==1) continue;
			len[a[i][1]]++;
			len[a[i][2]]++;
			if(num[a[i][1]][a[i][2]]==0){
				u[a[i][1]][len[a[i][1]]]=a[i][2];
				num[a[i][1]][a[i][2]]=t[i][1]+t[i][2];
				u[a[i][2]][len[a[i][2]]]=a[i][1];
				num[a[i][2]][a[i][1]]=t[i][1]+t[i][2];
			}else if(num[a[i][1]][a[i][2]]>t[i][1]+t[i][2]){
				num[a[i][1]][a[i][2]]=t[i][1]+t[i][2];
				num[a[i][2]][a[i][1]]=t[i][1]+t[i][2];
			}
		}while(q--){
			fill(f+1,f+n+1,0);
			ansA=0;
			cin>>x>>y;
//			cout<<x<<" "<<y<<endl;
			dfsA(x,0);
			cout<<ansA+w[x]+w[y]<<endl;
		}return 0;
	}if(fb){
		for(int i=1;i<=n;i++){
			for(int j=1;j<=k[i];j++){
				to[a[i][j]][0]++;
				to[a[i][j]][to[a[i][j]][0]]=i;
			}
		}
		while(q--){
			ansB=0;
			fill(f+1,f+n+1,0);
			cin>>x>>y;
			dfsB(x,1);
			cout<<ansB*2*T+w[x]+w[y]<<endl;
		}
	}
	while(q--){
		
	}
	return 0;
}
// zhe ge po ti gan za zhe me chang.
// wo ** yao re si le.
// 15:30 wo zhong yu ba shu ru xie wan le
// B - min(zhan tai)
// it is a DP, but i cant do it.
// DFS jian zhi ?
// wo cao , wo zuo bian de ge men zai wan windows zi dai de zhi pai you xi .?
// A - AC? --16:35
// made gei ni le.
// cao
