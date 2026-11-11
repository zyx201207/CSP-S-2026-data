#include<bits/stdc++.h>
using namespace std;
const int N=1e5+5;
int a[N],f[N];
void solve(){
	int cnt=0;
	int n,d,x,y;
	cin>>n>>d>>x;
	for(int i=2;i<=n;i++){
		cin>>y;
		a[i-1]=y-x;
		x=y;
	}
	int distence=0;
	for(int i=1;i<n;i++){
		distence+=a[i];
		f[i+1]=cnt+1;
		if(distence>d){
			cnt++;
			distence=a[i];
		}
	}
	int ans=0;
	for(int i=2;i<=n;i++){
		if(f[i+1]%2==0) ans++;
	}
	cout<<ans<<endl;
	return ;
}
int main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	int c,T;
	cin>>c>>T;
	while(T--) solve();
	return 0;
} 