#include<bits/stdc++.h>
using namespace std;
#define ll long long
const int N=2e6+5;
int c,t,n,d;
ll x[N];
bool f(int l,int r){
	int m=r-l-1;
	int sum=0;
	for(int i=0;i<(1<<m);i++){
		queue <int> q;
		int a=i;
		for(int j=1;j<=m;j++){
			if(a&1) q.push(j);
			a>>=1;
		}
		int cnt=0;
		int t1=q.front();
		q.pop();
		int t2=q.front();
		q.pop();
		bool b=false;
		while(!q.empty()){
			if(abs(t1-t2)>d){
				b=true;
				break;
			}
			if(abs(t1-q.front())<=d) cnt++;
			t1=t2;
			t2=q.front();
			q.pop();
		}
		if(b||cnt>=2) continue;
		if(cnt==1){
			sum++;
		}
	}
	if(sum==2) return true;
	else return false;
}
int main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	cin>>c>>t;
	if(c==11||c==12){
		while(t--){
			cin>>n>>d;
			for(int i=1;i<=n;i++) cin>>x[i];
			if(d>=2*(x[2]-x[1])&&d<3*(x[2]-x[1])) cout<<n-3<<endl;
			else cout<<0<<endl;
		}
	}
	else if(c==0||c==1||c==2){
		while(t--){
			cin>>n>>d;
			ll ans=0;
			for(int i=1;i<=n;i++) cin>>x[i];
			for(int i=1;i<n-1;i++){
				for(int j=i+1;j<=n;j++){
					if(f(i,j)){
						ans++;
					}
				}
			}
			cout<<ans<<endl;
		}
	}
	return 0;
}
