#include<bits/stdc++.h>
using namespace std;
const int N=5e3+5;
int c,T,n,d,a[N],mn[N][N],pos,k; 
int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0); 
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	cin>>c>>T;
	while(T--){
		cin>>n>>d;
		int ans=0;
		for(int i=1;i<=n;i++)
			cin>>a[i];
		for(int i=1;i<=n;i++)
			for(int j=i+1;j<=n;j++)
				if(a[j]-a[i]==2*d-1)
					ans++;
		cout<<ans<<'\n';	
	}
}
