#include<bits/stdc++.h>
#define INF 1e18
using namespace std;
typedef long long ll;
const int N=5e5+5;
int n,m;
int a[N];
int d[N];
ll sum[N];
ll maxn=-INF;
int res;
bool fA=1,fB=1;
int f(int i,int j,int k,int l,int o){
	int b[15];
	b[1]=a[1]+i;
	b[2]=a[2]+j;
	b[3]=a[3]+k;
	b[4]=a[4]+l;
	b[5]=a[5]+o;
	int cnt=0,ln=1;
	for(int d=2;d<=n;d++){
		if(b[d]!=b[d-1]) ln=0;
		ln++;
		cnt=max(cnt,ln);
	}
	return cnt;
}
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin>>n>>m;
	for(int i=1;i<=n;i++) cin>>a[i];
	for(int i=1;i<=n;i++) maxn=max(maxn,abs(a[i])*1LL);
	for(int i=1;i<=n;i++) if(a[i]!=i) fA=0;
	for(int i=2;i<=n-1;i++) if(a[i+1]-a[i]!=a[i]-a[i-1]) fB=0;
	if(fA){//15pts
		ll ans=0;
		for(int i=1;i*(i-1)<=2*m;i++) ans=i;
		cout<<ans;
	}
	else if(fB){//15pts
		int d=a[2]-a[1];
		ll ans=0;
		for(int i=1;i*(i-1)*d<=2*m;i++) ans=i;
		cout<<ans;
	}
	else if(n<=5&&m<=10){//10pts
		for(int i=0;i<=m;i++) for(int j=0;i+j<=m;j++) for(int k=0;i+j+k<=m;k++) for(int l=0;i+j+k+l<=m;l++) for(int o=0;i+j+k+l+o<=m;o++) res=max(res,f(i,j,k,l,o));
		cout<<res;
	}
	else{//?pts
		sort(a+1,a+1+n);
		for(int i=1;i<=n;i++) d[i]=a[i]-a[i-1];
		sort(d+1,d+1+n);
		for(int i=n;i>=1;i++) sum[i]=sum[i+1]+d[i];
		sort(sum+1,sum+1+n);
		for(int i=1;i<=n;i++){
			if(m<sum[i]){
				cout<<i;
				return 0;
			}
		}
	} 
	return 0;
}
