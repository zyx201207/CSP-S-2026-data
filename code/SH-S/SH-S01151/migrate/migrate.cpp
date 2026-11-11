#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N=200009;

int c,t,n,d;
ll x[N];
int main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0),cout.tie(0);
	cin>>c>>t;
	while(t--){
		cin>>n>>d;
		if(n<=3){
			cout<<0<<'\n';
			continue;
		} 
		bool ok=1;
		for(int i=1;i<=n;i++){
			cin>>x[i];
			if(i>2&&x[i]-x[i-1]!=x[i-1]-x[i-2])	ok=0;
		}
		if(x[n]-x[n-1]>d||n<4)	cout<<0<<'\n';
		else cout<<n-3<<'\n';
	}
	return 0;
}
