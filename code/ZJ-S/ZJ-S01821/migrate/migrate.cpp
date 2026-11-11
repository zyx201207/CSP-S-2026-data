#include<bits/stdc++.h>
#define int long long 
using namespace std;
const int N=5e3+10;
int c,t,n,d,a[N];
int f[N][N];
int main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0),cout.tie(0);
	cin>>c>>t;
	while(t--){
		cin>>n>>d;
		for(int i=1;i<=n;i++)cin>>a[i];
		if(n<=3||d==1) {
			cout<<0<<endl;
			continue;
		}
		for(int i=2;i<=n;i++){
			if((a[i]-a[i-1])>d){
				n=i-1;
				break;
			}
		}
		cout<<n-4+1<<endl;
	}
	return 0;
}