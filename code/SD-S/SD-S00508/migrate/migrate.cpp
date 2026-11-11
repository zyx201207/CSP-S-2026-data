#include<bits/stdc++.h>

#define int long long


using namespace std;

const int N=2e6+5,inf=1e18;
int x[N],n,d,pp[333],mi;

int check(int l,int r,int st){
	int k=0;
	for(int i=0;i<n;i++){
		if((st>>i)&1){
			if(i+1<=l||i+1>=r) return 0;
			pp[++k]=i+1;
		}
	}
	pp[0]=l;
	pp[k+1]=r;
	for(int i=1;i<=k+1;i++) if(x[pp[i]]-x[pp[i-1]]>d) return 0;
//	mi=min(mi,k+1);
	return k+1;
}

signed main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	
	int C,T;
	cin>>C>>T;
	while(T--){
		cin>>n>>d;
		for(int i=1;i<=n;i++){
			cin>>x[i];
		}
		int cnt=0;int mi=inf;
		for(int i=1;i<=n;i++){
			for(int j=i+1;j<=n;j++){
				for(int st=0;st<(1<<n);st++){
					mi=min(mi,check(i,j,st));
				}
			}
		}
		for(int i=1;i<=n;i++){
			for(int j=i+1;j<=n;j++){
				for(int st=0;st<(1<<n);st++){
					if(check(i,j,st)==mi) cnt++;
				}
			}
		}
		
		cout<<cnt<<"\n";
		
	}
	
	return 0;
} 
