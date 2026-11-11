#include<bits/stdc++.h>
using namespace std;
#define ll long long
const int N=1000007;
int c,t,a[N],n,b[N];
ll d,x[N];
ll dis[307][307],cnt[307][307],k[307];
//a[i] i最远到a_i
//b[j] j最远到b_j 
bool ok(int x,int y){
	return (a[x]>=y);
}
void solve1(){
	int l=1,r=1;
	while(r<=n){
		if(x[r]-x[l]<=d) r++;
		else{
			a[l]=r-1;
			l++;
		}
	}
	for(int i=l;i<=n;i++) a[i]=n;
	int cttt=1;
	ll Ans=0;
	for(int i=1;i<=n;i++){
		k[i]=cttt;
		if(a[i]==i) cttt++;
	}
	for(int j=2;j<=n;j++){
		for(int i=j-1;i>=1;i--){
			if(k[i]!=k[j]) continue;
			dis[i][j]=dis[a[i]][j]+1;
			if(dis[i][j]==1){
				cnt[i][j]=1;
				continue;
			}
			int kk=min(a[i],j);
			while(dis[kk][j]==dis[i][j]-1){
				cnt[i][j]+=cnt[kk][j];
				kk--;
			}
		}
	}
	for(int i=1;i<=n;i++){
		for(int j=i;j<=n;j++){
			if(cnt[i][j]==2) Ans++;
		}
	}
	for(int i=1;i<=n;i++){
		for(int j=i;j<=n;j++){
			dis[i][j]=0;
			cnt[i][j]=0;
		}
	}
	cout<<Ans<<endl;
}

void solveA(){
	ll D=x[2]-x[1];
	ll stp=d/D;
	if(stp<=1) cout<<0<<endl;
	else cout<<max(n-2*stp+1,0ll)<<endl;
}
void solveB(){
	int l=1,r=1;
	ll Ans=0;
	while(r<=n){
		if(x[r]-x[l]<=d) r++;
		else{
			a[l]=r-1;
			l++;
		}
	}
	for(int i=l;i<=n;i++) a[i]=n; 
	if(l==1||l==n){
		cout<<0<<endl;
		return;
	}
	
}
void solve(){
	cin>>n>>d;	
	for(int i=1;i<=n;i++) cin>>x[i];	
	if(c==11||c==12) solveA(); 
	else if(c==13||c==14) solveB();
//	else if(c>=15&&c<=19) solveC();
	else if(c<=6) solve1();
}
int main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	cin>>c>>t;
	for(int i=1;i<=t;i++) solve();
	return 0;
} 
