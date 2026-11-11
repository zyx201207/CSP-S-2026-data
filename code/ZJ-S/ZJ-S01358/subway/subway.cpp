#include<bits/stdc++.h>

using namespace std;

#define int long long

#define IOS ios::sync_with_stdio(0),cin.tie(0),cout.tie(0)

#define endl "\n"

const int N=2e6+10,M=2e3+10;

int c,n,m,d,q;

int k;

int w[N];

int a[M][M],t[M][M];

int f[N];

int find(int x) {
	
	if(x==f[x]) return x;
	
	return f[x]=find(x);
	
}

int qiu_zhi(int l,int r) {
	
	for(int i=1;i<=n;i++) {
			
		for(int j=1;j<=k;j++) {
				
			if(a[i][j]==l&&a[i][j+1]==r) {
				
				return t[i][j]+t[i][j+1] ;
				
			}
			
		}
			
	}
	
}

int solve(int l,int r) {
	
	int ans=0;
	
	if(f[r]==l||f[l]==r) return w[l]+w[r]+qiu_zhi(l,r);
		
	int sum=w[l]+w[r];	
	
	while(1) {
		
		if(f[r]==l) break;
		
		sum+=qiu_zhi(f[r],r);
		
		r=f[r];
		
	}
	
	sum+=qiu_zhi(l,r);
	
	return sum;
	
}

signed main() {
	
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	
	IOS;
		
	cin>>c>>n>>m>>d>>q;
	
	for(int i=1;i<=m;i++) cin>>w[i]; 
	
	for(int i=1;i<=max(n,m);i++) f[i]=i;
	
	for(int i=1;i<=n;i++) {
		
		int kk;cin>>kk;k=max(k,kk);
		
		cin>>a[i][1]>>t[i][1];
		
		for(int j=2;j<=kk;j++) {
			
			cin>>a[i][j]>>t[i][j];	
			
			f[a[i][j]]=a[i][j-1];
			
		}
		
	}
	
	while(q--) {
		
		int l,r;cin>>l>>r;
		
		cout<<solve(l,r)<<endl; 
		
	}
	
	return 0;
	
} 
