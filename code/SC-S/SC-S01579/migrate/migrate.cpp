#include<bits/stdc++.h>
#define int long long 
#define PII pair<int,int> 
using namespace std;
const int N = 5100,mod=1e9+7,inf = 1e18;
mt19937 rnd(time(0));
int c,T;
int n,d,a[N],f[N][N],w[N][N],ans,l[N];
void init(){
	for(int i=1;i<=n;i++){
		l[i]=1;
		for(int j=1;j<=n;j++) f[i][j]=inf;
	}
} 
signed main(){
	cin.tie(0)->sync_with_stdio(0);
    freopen("migrate.in","r",stdin);
    freopen("migrate.out","w",stdout);
    cin>>c>>T;
    while(T--){
    	cin>>n>>d;
    	for(int i=1;i<=n;i++){
    		cin>>a[i];
		}
		a[n+1]=inf;
		init();
		for(int i=1;i<=n;i++){
			int x=a[i];
			int id=upper_bound(a+1,a+1+n,x+d)-a-1;
			if(l[id]==1) l[id]=i;
			//cout<<i<<" "<<id<<"\n";
			for(int j=i;j<=id;j++) f[i][j]=1;
		}
//		for(int i=1;i<=n;i++){
//			cout<<i<<" "<<l[i]<<"\n";
//		}
		ans=0;
		for(int i=1;i<=n;i++){
			for(int j=i+1;j<=n;j++){
				for(int k=i+1;k<=j;k++){
					f[i][j]=min(f[i][j],f[i][k]+f[k][j]);
				}
		   }
	    }
		for(int i=1;i<=n;i++){
			for(int j=i+1;j<=n;j++){
				if(i>=l[j]) continue;
				int pp=0;
				for(int k=l[j];k<j;k++){
					//cout<<i<<" "<<j<<" "<<k<<"\n";
					if(f[i][k]+f[k][j]==f[i][j]){
						pp++;
					}
				}
				if(pp==2) ans++;
			}
		}
		cout<<ans<<"\n";
	}
    return 0;
}
/*
0 2
4 2
1 2 3 4
5 2
1 2 3 4 5

0 1
4 2
1 2 3 4

0 1
6 3
1 2 3 4 5 6

0 1
7 3
1 2 3 4 5 8 9 
*/