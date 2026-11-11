#include<bits/stdc++.h>
using namespace std;
const int N=2e6+5;
typedef long long ll;
ll c,T,f[5005][5005];
ll mi[N],a[N],ans;
bool check(int x,int y,ll d){
	int mincost=0,through[N];
	for(int i=x;i<=y;i++){
		int j=i;
		while(a[j]-a[i]<d&&j<=y) j++;
		through[++mincost]=--j;
		i=j;
	}
	int j,tot=1;
	for(int i=1;i<=mincost;i++){
		j=through[i];
		if(a[through[i+1]]-a[j]<d) tot++;
	}
	if(tot!=2) return false;
	else return true;
}
int main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	cin>>c>>T;
	while(T--){
		ll n,d; cin>>n>>d;
		for(int i=1;i<=n;i++) cin>>a[i];
		for(int i=1;i<=n;i++){
			for(int j=i;j<=n;j++){
				if(check(i,j,d)) ans++;
			}
		}
		cout<<ans<<'\n';
	}
	return 0;
}
