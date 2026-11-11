#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N=2001000;
int _,t,n,d,x[N],L[N],R[N],c[N][2],mx[N],mi[N];
int count(int p,int l,int r){return max(min(mx[p],r)-max(mi[p],l)+1,0ll);}
int solve(int l,int r){
	if(l>r) return 0;
	int s=0;
	for(int i=l,j=l;i<=r;i++){
		while(j<r&&x[j+1]-x[i]<=d) ++j;
		L[i]=j;
	}
	for(int i=r,j=r;i>=l;i--){
		while(j>l&&x[i]-x[j-1]<=d) --j;
		R[i]=j,mx[j]=max(mx[j],i),mi[j]=min(mi[j],i);
	}
	for(int i=l;i<r;i++){
		int j=i,k=0,l=0;
		while(L[j]!=j){
			if(k&&j-R[L[j]]>1) break;
			if(k&&j-R[L[j]]==1){
				if(l==1) break;
				l=1;
			}
			k=1,j=L[j],++c[j][l];
		}
	}
	for(int i=l;i<=r;i++) cout<<c[i][0]<<' '<<c[i][1]<<endl;
	for(int i=l+1;i<=r;i++){
		s+=c[i][1]*(1+count(i,i+1,L[i]-1))+c[i][0]*count(i-1,i+1,L[i]-1);
	}
	return s;
}
void init(){
	for(int i=1;i<=n;i++) c[i][0]=c[i][1]=0;
	for(int i=1;i<=n;i++) mx[i]=-1e9,mi[i]=1e9;
}
void solve(){
	cin>>n>>d,init();
	for(int i=1;i<=n;i++) cin>>x[i];
	int p=1,res=0;
	for(int i=2;i<=n;i++) if(x[i]-x[i-1]>d) res+=solve(p,i-1),p=i;
	res+=solve(p,n);
	cout<<res<<'\n';
}
signed main(){
	freopen("migrate.in","r",stdin);freopen("migrate.out","w",stdout);
	ios::sync_with_stdio(0),cin.tie(0);
	cin>>_>>t; while(t--) solve();
}