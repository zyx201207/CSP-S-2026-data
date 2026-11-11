#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N=5e5+5;
int a[N],n,m,sum[N],speBd,sm[N],smnm;
bool speA,speB,alsm;
signed main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	cin>>n>>m;
	for(int i = 1;i<=n;i++){
		cin>>a[i];
		
		if(a[i]!=i) speA=1;
		if(i==2) speBd=a[2]-a[1];
		if(i>2&&a[i]-a[i-1]!=speBd) speB=1; 
		if(i>=2&&a[i]!=a[i-1]) alsm=1;
	}
	sort(a+1,a+n+1);
	
	for(int i = 1;i<=n;i++) sum[i]=sum[i-1]+a[i];
	for(int i = 1;i<n;i++) if(a[i]==a[i+1]) sm[i]=1;
	for(int i = n-1;i;i--){
		sm[i]+=smnm;
		if(sm[i]) smnm++;
		if(a[i-1]!=a[i]) smnm=0;	
	}
	
	if(!alsm) {
		cout<<n<<"\n";
		return 0;
	}	
	if(!m){
		int ns=0;
		for(int i = 1;i<n;i++){
			int t=0; 
			while(a[i]==a[i+1]&&i<n){
				i++;
				t++;
			}ns=max(t,ns);
		}cout<<ns+1<<"\n";
		return 0;
	}
	if(!speA){//No.13-15
		int i=(-1+sqrt(1+8*m))/2;
		for(;i<=n;i++) if(i*(i+1)>2*m) {
			cout<<i<<"\n";
			return 0;
		}	
	}
	if(!speB){//No.16-18 
		speBd=a[2]-a[1];
		int nds=a[1]-1,cp=0;
		for(int i = 1;i<=n;i++) a[i]-=nds;
		for(int i=1;i<=n;i++){
			cp+=speBd*(i-1);
			if(cp>m) {
				cout<<i-1<<"\n";
				return 0;
			}
		}
	}
	int nns=1;
	for(int i = 1;i<=n;i++){
		for(int j = i+nns;j<=n;j=max(j+1,j+sm[j])){
			int t=(j-1-i+1)*a[j]-sum[j-1]+sum[i-1];
			if(t>m) continue;
			nns=max(nns,j-i+1);
		}
	}cout<<nns<<"\n";
	return 0;
} 
