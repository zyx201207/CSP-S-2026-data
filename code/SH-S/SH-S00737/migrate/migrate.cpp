#include<bits/stdc++.h>
using namespace std;
long long c,t,n,d,x[2000010],a[2000010],l[2000010],r[2000010],cnt,nx,ny,ans;
void solve(){
	cnt=0;
	ans=0;
	cin>>n>>d;
	for(int i=1;i<=n;i++){
		cin>>x[i];
		a[i]=0;
		l[i]=0;
		r[i]=0;
	}
	for(int i=1;i<=n-3;i++){
		if(x[i+3]-x[i]>d&&x[i+2]-x[i]<=d&&x[i+3]-x[i+1]<=d){
			l[i]=1;
			r[i+3]=1;
			a[++cnt]=i;
		}
	}
	for(int i=1;i<=cnt;i++){
		nx=a[i];
		ny=nx+3;
		while(nx>1&&!l[nx-1]&&x[nx]-x[nx-1]<=d){
			nx--;
		}
		while(ny<n&&!r[ny+1]&&x[ny+1]-x[ny]<=d){
			ny++;
		}
		ans+=(a[i]-nx+1)*(ny-a[i]-2);
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
	fclose(stdin);
	fclose(stdout);
} 
