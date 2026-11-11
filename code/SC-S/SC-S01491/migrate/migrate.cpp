#include<bits/stdc++.h>
using namespace std;
using ll=long long;
const int N=2e6+4;
inline int read(){
	int x=0,f=1; char c=getchar();
	if(c>='0'&&c<='9') x=x*10+c-'0';
	else if(c=='-') f=-1;
	return x*f;
}
int c,t,n;
bool far[N];
ll path[N];
ll d,x[N];
void solveA(){
	while(t--){
		cin>>n>>d;
		for(int i=1;i<=n;i++) cin>>x[i];
		if(n==1){
			cout<<0<<'\n';
			continue;
		}
		ll dif=x[2]-x[1];
		if(dif>=d){
			cout<<0<<'\n';
			continue;
		}
		ll ans=0;
		for(int i=2;i*2-1<=n;i++){
			if(1LL*i*dif<=d&&d<(i+1)*dif) ans+=n-i*2+1;
		}
		cout<<ans<<'\n';
	}
}
int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	cin>>c>>t;
	if(c==11||c==12) solveA();
	while(t--){
		cin>>n>>d;
		for(int i=1;i<=n;i++){
			cin>>x[i];
		}
		if(n==1){
			cout<<0<<'\n';
			continue;
		}
		for(int i=1;i<n;i++){
			if(x[i]-x[i-1]>d&&x[i+1]-x[i]>d){
				far[i]=1;
			}
		}
	}
	return 0;
}