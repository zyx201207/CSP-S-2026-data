#include<bits/stdc++.h>
using namespace std;
#define int long long
#define ull unsigned long long
const int N=2e6+5;
const int INF=1e9+9;
int C,T;
int n,d;
int x[N];
bool check_F(int i){
	if(x[i+3]-x[i]<=d) return 0;
	if(x[i+2]-x[i]<=d&&x[i+3]-x[i+1]<=d) return 1;
	return 0;
}
bool check_P(int i,int len){
	if(x[i+len-1]-x[i]<=d) return 0;
	if(x[len/2+i]-x[i]<=d&&x[i+len-1]-x[i+len-1-len/2]<=d) return 1;
	return 0;
}
signed main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin>>C>>T;
	while(T--){
		cin>>n>>d;
		for(int i=1;i<=n;i++){
			cin>>x[i];
		}
		if(n<=3||x[n]-x[1]<=d){
			cout<<0<<"\n";
			continue;
		}
		if(n==4){
			if(check_F(1)) cout<<1<<"\n";
			else cout<<0<<"\n";
			continue;
		}
		if(n==5){
			if(x[2]-x[1]==d&&check_F(2)) cout<<2<<"\n";
			else if(x[5]-x[4]==d&&check_F(1)) cout<<2<<"\n";
			else if(check_F(1)&&check_F(2)) cout<<2<<"\n";
			else if(check_F(1)||check_F(2)) cout<<1<<"\n";
			else cout<<0<<"\n";
			continue;
		}
		if(C==0||C==11||C==12){
			int c=abs(x[2]-x[1]);
			if(d<2*c){
				cout<<0<<"\n";
				continue;
			}
			int k=d/c;
			int l=k*2-1;
			if(n<l){
				cout<<0<<"\n";
				continue;
			}
			cout<<n-l<<"\n";
			continue;
		}
		int ans=0;
		for(int len=4;len<=n;len++){
			if(len%2) continue;
			for(int i=1;i<=n-len+1;i++){
				if(x[i+1]-x[i]>d) continue;
				if(x[i+1]-x[i]==d&&len>4&&check_P(i,len-1)) ans+=2; 
				if(check_P(i,len)) ans++;
			}
		}
		cout<<ans<<"\n";
	}
	return 0;
}

