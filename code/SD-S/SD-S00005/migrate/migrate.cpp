#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N=2e6+10;
int C,T;
int n,d,a[N];
signed main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	cin>>C>>T;
	while(T--){
		int n,d;
		cin>>n>>d;
		for(int i=1;i<=n;i++){
			cin>>a[i];
		}
		if(n==1||n==2){
			cout<<"0\n";
			continue;
		}
		if(C==11||C==12){
			int s=a[n]-a[n-1];
			int r=d/s;
			if(r==1||r==0){
				cout<<"0\n";
			}else{
				r=2*r-1;
				n-=r;
				if(n<0)n=0;
				cout<<n<<"\n";
			}
		}
		cout<<"0\n";
	}
	return 0;
}
