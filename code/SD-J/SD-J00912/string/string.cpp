#include<bits/stdc++.h>
#define ll long long
using namespace std;
struct N{
	ll nu;
	char c;
	bool f;
};
N a[200010],b[200010],x,y;
ll ans,n,nix=1,niy=1;
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i].nu>>a[i].c;
		b[n-i+1].nu=a[i].nu;
		b[n-i+1].c=a[i].c;
	}
	x.f=0,y.f=0;
	while(nix<=n||niy<=n){
		if(x.f==0&&y.f==0){
			if(a[nix].c==b[niy].c){
				if(a[nix].nu<b[niy].nu){
					y.f=1;
					y.nu=b[niy].nu-a[nix].nu;
					y.c=b[niy].c;
					nix++;
				}
				else if(a[nix].nu>b[niy].nu){
					x.f=1;
					x.nu=a[nix].nu-b[niy].nu;
					x.c=a[nix].c;
					niy++;
				}
				else nix++,niy++;
			}
			else{
				ans+=min(a[nix].nu,b[niy].nu);
				if(a[nix].nu<b[niy].nu){
					y.f=1;
					y.nu=b[niy].nu-a[nix].nu;
					y.c=b[niy].c;
					nix++;
				}
				else if(a[nix].nu>b[niy].nu){
					x.f=1;
					x.nu=a[nix].nu-b[niy].nu;
					x.c=a[nix].c;
					niy++;
				}
				else nix++,niy++;
			}
		}
		else if(x.f==1){
			if(x.c==b[niy].c){
				if(x.nu<b[niy].nu){
					y.f=1;
					y.nu=b[niy].nu-x.nu;
					y.c=b[niy].c;
					nix++;
					x.f=0;
				}
				else if(x.nu>b[niy].nu){
					x.f=1;
					x.nu=x.nu-b[niy].nu;
					x.c=x.c;
					niy++;
				}
				else x.f=0,nix++,niy++;
			}
			else{
				ans+=min(x.nu,b[niy].nu);
				if(x.nu<b[niy].nu){
					y.f=1;
					y.nu=b[niy].nu-x.nu;
					y.c=b[niy].c;
					nix++;
					x.f=0;
				}
				else if(x.nu>b[niy].nu){
					x.f=1;
					x.nu=x.nu-b[niy].nu;
					x.c=x.c;
					niy++;
				}
				else x.f=0,nix++,niy++;
			}
		}
		else {
			if(a[nix].c==y.c){
				if(a[nix].nu<y.nu){
					y.f=1;
					y.nu=y.nu-a[nix].nu;
					y.c=y.c;
					nix++;
				}
				else if(a[nix].nu>y.nu){
					x.f=1;
					x.nu=a[nix].nu-y.nu;
					x.c=a[nix].c;
					niy++;
					y.f=0;
				}
				else y.f=0,nix++,niy++;
			}
			else{
				ans+=min(a[nix].nu,y.nu);
				if(a[nix].nu<y.nu){
					y.f=1;
					y.nu=y.nu-a[nix].nu;
					y.c=y.c;
					nix++;
				}
				else if(a[nix].nu>y.nu){
					x.f=1;
					x.nu=a[nix].nu-y.nu;
					x.c=a[nix].c;
					niy++;
					y.f=0;
				}
				else y.f=0,nix++,niy++;
			}
		}
	}
	cout<<(ans+1)/2;
	return 0;
} 
