#include<bits/stdc++.h>
using namespace std;
int c,t;

void check(){
	int n,d,x[205],b[205][587],ans;
	cin>>n>>d;
	for(int i=1;i<=n;i++){
		cin>>x[i];x[i]+=x[i-1];
	}
	for(int i=n-2;i>=1;i--){
		for(int j=1;j<=n;j++){
			for(int z=1;z<=n-j;z++){
				if(x[j+i]-x[j]<d&&x[j+i+z]-x[j+z]<d)
				ans++;
			}
		}
	}
	cout<<ans<<endl;
}
int main(){
	ios::sync_with_stdio(false);
	cin.tie(0),cout.tie(0);
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	cin>>c>>t;
	for(int i=1;i<=t;i++)check();
	return 0;
}
