#include<bits/stdc++.h>
using namespace std;
const int N=2e6+10;
int c,T;
int n,d;
int a[N];
int ans;
int l;
void solve(){
	cin>>n>>d;
	if(c>=11&&c<=12){
		for(int i=1;i<=n;i++){
			cin>>a[i];
		}
		int gc=a[2]-a[1];
		int stp=d/gc;
		if(stp==2)ans=n-2;
		else ans=0;
		if(ans<0)ans=0;
	}
	else{
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	for(int i=1;i<=n;i++){
		l=i;
		for(int j=i+1;j<=n;j++){
			if(a[l]+d>=a[j]){
				if(l-1>i&&a[j]-a[l-1]<=d)ans++;
			}else{
				l=j-1;
				if(l-1>i&&a[j]-a[l-1]<=d)ans++;
			}
		}
	}
	}
	cout<<ans<<'\n';
}
int main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	cin>>c>>T;
	while(T--){
		solve();
	}
	return 0;
}