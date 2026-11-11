#include<bits/stdc++.h>
using namespace std;
#define int long long
const int N=2e6+10,inf=2e18+10;
int kkksc03;
int n,d,a[N];
int tor[N],tol[N];
pair<int,int>operator+(pair<int,int>a,pair<int,int>b){
	if(a.first==b.first)return {a.first,min(3ll,a.second+b.second)};
	if(a.first<b.first)return a;
	return b;
}
int work(int i,int j,int k){
	if(j-2>=i&&a[k]-a[j-2]<=d)return 2;
	if(j-1>=i&&a[k]-a[j-1]<=d)return 1;
	return 0;
}
int dtpq[N],dtq[N];
int f[N][3][3];
void solve(){
	cin>>n>>d;
	for(int i=1;i<=n;i++){
		memset(f[i],0,sizeof(f[i]));
		dtpq[i]=dtq[i]=0;
	}
	for(int i=1;i<=n;i++)cin>>a[i];
	tor[n]=n;
	for(int i=n-1;i>=1;i--){
		tor[i]=tor[i+1];
		while(a[tor[i]]-a[i]>d)tor[i]--;
	}
	tol[1]=1;
	for(int i=2;i<=n;i++){
		tol[i]=tol[i-1];
		while(a[i]-a[tol[i]]>d)tol[i]++;
	}
	for(int i=1;i<=n;i++){
		int p1=i,p0=i;
		for(int k=1<<20;k;k>>=1){
			if(p1+k<=tor[i]&&tol[p1+k]<i-1)p1+=k;
			if(p0+k<=tor[i]&&tol[p0+k]<i-0)p0+=k;
		}
		dtpq[i]=p0-p1;
		dtq[i]=tor[i]-p0;
	}
	int ans=0;
//	for(int i=1;i<=n;i++){
//		int p=1,q=1;
//		int j=tor[i];
//		while(j!=tor[j]){
//			int P=3,Q=3;
//			if(p+q==2)ans+=dtpq[j];
//			if(q==2)ans+=dtq[j];
//			if(j==tor[j]-1)P=q;
//			else{
//				if(tol[tor[j]-1]<j-1)P=3;
//				else if(tol[tor[j]-1]==j-1)P=p+q;
//				else P=q;
//			}
//			if(tol[tor[j]]<j-1)Q=3;
//			else if(tol[tor[j]]==j-1)Q=p+q;
//			else Q=q;
//			p=P;q=Q;
//			j=tor[j];
//		}
//	}
	for(int i=1;i<=n;i++)f[tor[i]][1-1][1-1]++;
	for(int i=1;i<=n;i++){
		if(tor[i]==i)continue;
		for(int p=1;p<=3;p++){
			for(int q=1;q<=3;q++){
				int P=3,Q=3;
				if(p+q==2)ans+=dtpq[i]*f[i][p-1][q-1];
				if(q==2)ans+=dtq[i]*f[i][p-1][q-1];
				if(i==tor[i]-1)P=q;
				else{
					if(tol[tor[i]-1]<i-1)P=3;
					else if(tol[tor[i]-1]==i-1)P=p+q;
					else P=q;
				}
				if(tol[tor[i]]<i-1)Q=3;
				else if(tol[tor[i]]==i-1)Q=p+q;
				else Q=q;
				P=min(P,3ll);
				Q=min(Q,3ll);
				f[tor[i]][P-1][Q-1]+=f[i][p-1][q-1];
			}
		}
	}
	cout<<ans<<"\n";
}
signed main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	ios::sync_with_stdio(false);cin.tie(0);
	int T;
	cin>>kkksc03>>T;
	for(int round=1;round<=T;round++){
		solve();
	}
	return 0;
}
/*
0 1
10 14
-31 -24 -17 -10 -3 4 11 18 25 32
*/
