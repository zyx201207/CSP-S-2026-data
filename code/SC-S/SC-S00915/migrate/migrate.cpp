#include<bits/stdc++.h>
#define N 1000005
#define int long long
using namespace std;
int a[N],f[N],g[N];
signed main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	int c,T;
	cin>>c>>T;
	while(T--){
		int n,d;
		cin>>n>>d;
		bool flag=true;
		for(int i=1;i<=n;i++){
			cin>>a[i];
			if(i>2&&a[i]-a[i-1]!=a[i-1]-a[i-2])flag=false;
		}
		if(flag){
			int tot=a[2]-a[1];
			int g=d/tot;
			g=2*g-1;
			if(g<=1)cout<<"0\n";
			else cout<<max(n-g,0ll)<<"\n";
			continue;
		}
		int cnt=0;
		for(int k=1;k<=n;k++){
			for(int i=1;i<=n;i++)f[i]=1e9,g[i]=0;
			f[k]=0,g[k]=1;
			for(int i=k+1;i<=n;i++){
				for(int j=i-1;j>=k;j--){
					if(a[i]-a[j]<=d){
						if(f[j]+1==f[i])g[i]+=g[j];
						else if(f[j]+1<f[i]){
							g[i]=g[j];
							f[i]=f[j]+1;
						}
					}else break;
				}
				if(g[i]==2)cnt++;
			}			
		}
		cout<<cnt<<"\n";
	}
	return 0;
}
/*
0 2
5 3
-2 -1 0 1 2
6 2
-4 -3 -2 -1 3 6
*/