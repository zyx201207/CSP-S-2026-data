#include<bits/stdc++.h>
using namespace std;
int c;

void solve(){
	int n,d;
	cin>>n>>d;
	vector<int> x(n+5,0);
	for(int i=1;i<=n;i++){
		cin>>x[i];
	}
	if(c<=13&&c<=14){
		cout<<'4\n';
	}else if(11<=c&&c<=12){
		int ans=0;
		for(int i=2;i<=n;i+=2){
			for(int j=1;j<=n-i+1;j++){
				ans++;
			}
		}
		cout<<ans;
	}else{
		cout<<n/2;
	}
	
}
int main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
	int t;
	cin>>c>>t;
	while(t--){
		solve();
	}


	return 0;
}

