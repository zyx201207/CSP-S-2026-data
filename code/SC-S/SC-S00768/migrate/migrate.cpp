#include<bits/stdc++.h>
#define int long long
using namespace std;

const int zero=0;
int c,t,d,n,a[2000005];

void ans(){
	if(c==11||c==12){
		for(int i=1;i<=n;i++){
			if((a[2]-a[1])*i<d&&(a[2]-a[1])*(i+1)>d){
				cout<<max(n-i-2,zero)<<'\n';
			}
		}
	}else{
		cout<<"0\n";
	}
}

signed main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","r",stdout);
	ios::sync_with_stdio(false),cin.tie(nullptr),cout.tie(nullptr);
	cin>>c>>t;
	while(t--){
		cin>>n>>d;
		for(int i=1;i<=n;i++) cin>>a[i];
		ans();
	}
	return 0;
}