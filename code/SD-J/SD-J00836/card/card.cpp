#include<bits/stdc++.h>
using namespace std;
#define F(i,s,e) for(int i=s;i<=e;i++)

const int N = 5e5+10,M = 3e5+10;
int a[N],t[M],tot;
int nx[N];//与ai相同的下一个i 
int id[N];
int vl[N];//vl i s>=i的最小值 
int nxx[N];//下一条边的标号  
int tag[N];//标号i被跳过的次数 
int st[N];//标号i的边的起点
int d[N],ans[M];
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	cin.tie(0)->sync_with_stdio(0);
	int n,m;cin>>n>>m;
	F(i,1,n+1) vl[i]=nx[i]=n+1;
	F(i,1,n){
		cin>>a[i];
		if(t[a[i]]) nx[t[a[i]]]=i,id[t[a[i]]]=++tot,st[tot]=t[a[i]];
		t[a[i]]=i;
	}
//	F(i,1,n) cout<<nx[i]<<'\n'; 
	F(i,1,n) vl[i]=i;for(int i=n-1;i>=1;i--) if(nx[vl[i]]==n+1&&nx[vl[i+1]]!=n+1) vl[i]=vl[i+1];
//	F(i,1,n) cout<<vl[i]<<'\n'; 
	F(i,1,n) if(nx[vl[nx[i]]]!=n+1) nxx[id[i]]=id[vl[nx[i]]];
	F(i,1,n){//i-th game
		int s=id[vl[i]];
		if(s) tag[s]++;
	}
	F(i,1,tot) if(nxx[i]) tag[nxx[i]]+=tag[i];
	F(i,1,tot){
		d[st[i]]+=tag[i];
		d[nx[st[i]]]-=tag[i];
	}
	F(i,1,n) d[i]+=d[i-1];
	F(i,1,n) if(nx[i]==n+1) ans[a[i]] = i - d[i];
	F(i,1,m) cout<<ans[i]<<' ';
	return 0;
}


