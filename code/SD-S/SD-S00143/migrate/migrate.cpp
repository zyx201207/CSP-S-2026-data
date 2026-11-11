#include<bits/stdc++.h>
#define int long long
#define INF (1ll<<62)
#define pii pair<int,int>
using namespace std;
int c,t,n,d;
int a[2000010];
signed main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	cin>>c>>t;
	while(t--){
		cin>>n>>d;
		for(int i=1;i<=n;i++)  cin>>a[i];
		if(c<=6){
			int sum=0;
			for(int i=1;i<=n-3;i++){
				for(int j=i+3;j<=n;j++){
					int op=0,f=1;
					for(int k=i+1;k<j;k++){
						if(a[k]-a[i]<=d and a[j]-a[k]<=d)  op++;
						if(op>2){
							f=0;
							break;
						}
					}
					if(f and op==2)  sum++;
				}
			}
			cout<<sum<<endl;
		}
		else   cout<<"unmgadtionprotedacion\n";
	}
	return 0;
}

