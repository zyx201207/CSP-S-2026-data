#include<iostream>
#include<stdio.h>
using namespace std;
#define int long long
const int N=2e6+5;
int c,t;
int n,d;
int tu[N];
int e[N],f[N];
int a,b;
signed main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	cin>>c>>t;
	while(t--){
		cin>>n>>d;
		int ans=0;
		for(int i=1;i<=n;i++)cin>>tu[i];
		for(int i=1;i<=n;i++){
			for(int j=i+1;j<=n;j++){
				a=i,b=j;
				for(int i=a;i<=b;i++){
					if(b-a>=d){
						ans++;
					}
				}
			}
		}
		cout<<ans<<'\n';
	}
	return 0;
}
