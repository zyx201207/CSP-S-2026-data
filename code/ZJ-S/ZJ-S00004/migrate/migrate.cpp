#include <bits/stdc++.h>
using namespace std;
#define ll long long
int ot,t,n,b[2000010],d[2000010];
int f[2000010],c[2000010];
ll a[2000010],m,s;
void solve(int l,int r){
	for(int i=l;i<=r;i++)
		b[i]=lower_bound(a+1,a+1+n,a[i]-m)-a;
	for(int i=l;i<=r;i++){
		f[i]=0,c[i]=0;
		for(int j=i+1;j<=r;j++){
			int x=max(b[j],i);
			f[j]=f[x]+1,c[j]=c[x];
			if(c[j]==2||x+1==j||f[x+1]>f[x]) continue;
			if(!c[x+1]) ++c[j];
			else c[j]=2;
			if(x+2==j||f[x+2]>f[x]) continue;
			c[j]=2;
		}
		for(int j=i+1;j<=r;j++)
			if(c[j]==1) s++;
	}
}
void solve2(int l,int r){
	for(int i=l;i<=r;i++)
		b[i]=lower_bound(a+1,a+1+n,a[i]-m)-a;
	int i=l;
	f[i]=0,c[i]=0;
	for(int j=i+1;j<=r;j++){
		int x=max(b[j],i);
		f[j]=f[x]+1,c[j]=c[x];
		if(c[j]==2||x+1==j||f[x+1]>f[x]) continue;
		if(!c[x+1]) ++c[j];
		else c[j]=2;
		if(x+2==j||f[x+2]>f[x]) continue;
		c[j]=2;
	}
	for(int j=i+1;j<=r;j++)
		if(c[j]==1) s+=(r-j+1);
}
int main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin>>ot>>t;
	while(t--){
		cin>>n>>m;
		bool A=true;
		for(int i=1;i<=n;i++){
			cin>>a[i];
			if(i>2&&a[i]-a[i-1]!=a[i-1]-a[i-2]) A=false;
		}
		if(A&&n>1){
			if(a[2]-a[1]>m) cout<<"0\n";
			else{
				s=0;
				solve2(1,n);
				cout<<s<<"\n";
			}
			continue;
		}
		if(n>5000){
			cout<<"0\n";
			continue;
		}
		a[n+1]=3e18;
		a[0]=-3e18;
		int l=1;
		s=0;
		for(int r=1;r<=n;r++)
			if(a[r]+m<a[r+1]){
				solve(l,r);
				l=r+1;
			}
		cout<<s<<"\n";
	}
 return 0;
}
