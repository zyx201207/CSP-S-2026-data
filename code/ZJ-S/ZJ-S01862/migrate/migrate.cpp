#include<bits/stdc++.h>
using namespace std;
#define int long long
const int N=2e5+10,M=5e3+10;
int T,C,n,m,k,ans=0;
int a[N],b[N],q[N];
bool vis[M][M];
int c[N][23];


bool check(int l,int r){
	int cnt=0,x=l,cnt2=0;
	for(int i=20;i>=0;i--){
		if(c[x][i]&&c[x][i]<=r) x=c[x][i],cnt+=(1<<i);
		if(x>=r) break;
	}	
	for(int i=l;i<=r;i++){
		if(c[c[i][0]-1][0]==c[i][1]) cnt2++;
		if(c[c[i][0]-2][0]==c[i][1]) return 0;
		if(c[i][0])i=c[i][0];
		else break;
	}
	return (cnt2==1);
}

void calc(){
	ans=0;
	cin>>n>>m;
	for(int i=1;i<=n;i++) cin>>a[min(i,N-1)],b[min(i,N-1)]=a[min(i,N-1)]-a[min(i,N-1)-1];

	if(C==11||C==12){
		int d=m/abs(a[2]-a[1]);
		if(d==0) cout<<0<<endl;
		else cout<<max(0ll,n-(d*2-1))<<endl;
		return;
	}
	if(C>=13) {
		cout<<0<<endl;
		return;
	}
	for(int i=1;i<=n;i++){
		for(int j=i+1;j<=n;j++){
			if(a[j]-a[i]<=m) c[i][0]=j;
			else break;
		}
	}
	for(int i=1;i<=n;i++){
		for(int j=20;j>=0;j--){
			c[i][j]=c[c[i][j-1]][j-1];
		}
	}
	
	for(int i=1;i<=n;i++){
		for(int j=i+1;j<=n;j++){
			ans+=check(i,j);
			if(b[j]>m) break;
		}
	}
	cout<<ans<<endl;
}

signed main(){
//	freopen("migrate4.in","r",stdin);
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0),cout.tie(0);
	cin>>C>>T;
	while(T--){
		calc();
	}
	return 0;
}
