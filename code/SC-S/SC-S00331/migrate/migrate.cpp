#include<bits/stdc++.h>
using namespace std;
#define int long long
int n,d,a[2000010],D,f[2000010][2][3],fa[2000010];//0 : =i , 1 : =i+1 ,2 : >i+1
vector<int>e[5010];
int c[310][310],t[310][310];
inline void solve(){
	cin>>n>>d;
	if(n==1){
		for(int i=1;i<=n;i++) cin>>a[i];
		cout<<"0\n";
		return;
	}
	for(int i=1;i<=n;i++){
		cin>>a[i],fa[i]=0;
		for(int j=0;j<2;j++) for(int k=0;k<3;k++) f[i][j][k]=0;
		f[i][0][0]=1;
	}
	for(int i=1,j=1;i<=n;i++){
		while(j<=n && a[j]-a[i]<=d) j++;
		if(i!=j-1) fa[i]=j-1;
	}
	int D=a[2]-a[1];
	bool flag=1;
	for(int i=3;i<=n;i++) if(a[i]-a[i-1]!=D) flag=0;
	if(flag==1){
		if(fa[1]<=2) cout<<"0\n";
		else if(fa[1]-1+fa[1]-2<=n) cout<<n-(fa[1]-1+fa[1]-2)<<"\n";
		else cout<<"0\n";
		return;
	}
	else if(n<=300){
		memset(c,0x3f,sizeof c);
		for(int i=1;i<=n;i++) c[i][i]=0;
		for(int i=1;i<=n;i++) for(int j=1;j<=n;j++) t[i][j]=0;
		for(int i=1;i<=n;i++) for(int j=1;j<=n;j++) if(abs(a[i]-a[j])<=d && i!=j) c[i][j]=1,t[i][j]=1;
		for(int k=1;k<=n;k++) for(int i=1;i<=n;i++) for(int j=1;j<=n;j++)
			if(c[i][j]>c[i][k]+c[k][j]) c[i][j]=c[i][k]+c[k][j],t[i][j]=t[i][k]*t[k][j];
			else if(c[i][j]==c[i][k]+c[k][j]) t[i][j]+=t[i][k]*t[k][j];
		int cnt=0;
		for(int i=1;i<=n;i++) for(int j=i+1;j<=n;j++) if(t[i][j]==2) cnt++;
		cout<<cnt<<"\n";
		return;
	}
//	else if(n<=5000){
//		for(int i=1;i<=n;i++){
//			if(fa[i]>i) e[i].push_back(fa[i]);
//			if(fa[i]>i+1) e[i].push_back(fa[i]),e[i].push_back(fa[i+1]);
//		}
//		for(int i=1;i<=n;i++){
//			
//		}
//		return;
//	}
	for(int i=1,j=1;i<=n;i++){
		while(j<=n && a[j]-a[i]<=d) j++;
		if(i!=j-1){
			fa[i]=j-1;
			if(i>2 && a[j-1]-a[i-1]<=d && a[j-1]-a[i-2]<=d){
				if(j-1==i+1) f[j-1][1][2]+=f[i][0][1],f[j-1][0][1]+=f[i][0][0];
				else if(j-1>=i+2) f[j-1][1][2]+=f[i][0][2],f[j-1][0][2]+=f[i][0][0];
			}
			else if(i>1 && a[j-1]-a[i-1]<=d){
				if(j-1==i+1) f[j-1][1][2]+=f[i][0][2],f[j-1][1][2]+=f[i][0][1],f[j-1][0][1]+=f[i][0][0];
				else if(j-1>=i+2) f[j-1][1][2]+=f[i][0][1]+f[i][0][2],f[j-1][0][2]+=f[i][0][0];
			}
			else{
				if(j-1==i+1)
					f[j-1][1][2]+=f[i][1][1],f[j-1][1][1]+=f[i][1][0],f[j-1][1][2]+=f[i][1][2],
					f[j-1][0][2]+=f[i][0][1],f[j-1][0][1]+=f[i][0][0],f[j-1][0][2]+=f[i][0][2];
				else if(j-1>=i+2)
					f[j-1][1][2]+=f[i][1][0]+f[i][1][1]+f[i][1][2],
					f[j-1][0][2]+=f[i][0][0]+f[i][0][1]+f[i][0][2];
			}
		}
	}
	int ans=0;
	for(int i=2;i<=n;i++){
		if(!fa[i-1] || !fa[i]) continue;
		ans+=(fa[i-1]-i)*f[i][0][1]+(fa[i]-fa[i-1])*f[i][1][1];
		ans+=(fa[i-1]-max(i,fa[i-2]))*f[i][0][2]+(fa[i]-fa[i-1])*f[i][1][2];
	}
	cout<<ans<<"\n";
}
signed main() {
	ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	int FW_number,t;
	cin>>FW_number>>t;
	while(t--) solve();
	return 0;
}
//怎么 30min 就 200 分了 
//去了 15min T4，回来发现 T3 太简单了 
//0 1
//6 3
//0 1 2 3 4 7

//0 1
//10 22
//0 7 14 21 28 35 42 49 56 63

//0 1
//8 3
//0 1 2 4 8 10 11 13

//假了，开赌 
