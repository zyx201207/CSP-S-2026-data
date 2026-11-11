#include<bits/stdc++.h>
#define For(i,j,k) for(int i=j;i<=k;i++)
#define ll long long
#define pb push_back
using namespace std; 
const int N=2e6+5;
int c,t;
void solve(){
	bool flag_a = true;
	int n,ans=0;
	long long d;
	cin>>n>>d;
	vector<long long>x(n+1);
	vector<long long>f(n+1);
	cin>>x[1];
	f[1]=0;
	For(i,2,n){
		cin>>x[i];
		f[i]=x[i]-x[i-1];
		if(f[i]!=f[i-1])flag_a =false;
	}
	for(int i=1;i<=n-1;i++){
		int dis=0;
		for(int j=i+1;j<=n;j++){
			dis+=f[j];
			if(dis>d&&(dis%d)>0&&j!=(i+1)){
				ans++;
			}
		}
	}
	cout<<ans<<endl;
}
int main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	cin>>c>>t;
	while(t--){
		solve();
	}
}
