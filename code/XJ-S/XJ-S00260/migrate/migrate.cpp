#include<bits/stdc++.h>
using namespace std;
const int N=2e6+12;
int c,t,n,l,r;
long long ans,x[N];
unsigned long long d;
int main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin >> c >> t;
	while(t--){
		r=0,ans=0;
		cin >> n >> d;
		for(int i=1;i<=n;i++){
			cin >> x[i];
			if(!r&&x[i]-x[1]>d) r=i; 
		}
		if(n<=3);
		else if(c==11||c==12){
			r=d/(x[2]-x[1]);
			if(r>1&&2*r<=n) ans=n-(2*r)+1;
		}
		else if(c==13||c==14){
			l=1;
			while(r<=n){
				while(x[r]-x[l]<=d) r++;
				if(r-l==3) ans+=n-r+1;
				while(x[r]-x[l]>d) l++;
			}
		}
		else{
			for(int i=1;i+3<=n;i++) ans+=n>i+2?1:n-i-2;
		}
		cout << ans << endl;
	}
	return 0;
}
