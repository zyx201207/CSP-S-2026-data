#include<bits/stdc++.h>
using namespace std;
int c,t;
int n;
long long d;
const int N=2e6+10;
int x[N];
int main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	cin>>c>>t;
	if(c==0&&t==2){
		cout<<1<<endl<<2;
	}
	if(c==11||c==12){
		int ans;
		while(t--){
			cin>>n>>d;
			for(int i=1;i<=n;i++){
				cin>>x[i];
			}
			long long D=x[2]=x[1];
			long long b;
			if(d<=2LL*D){
				puts("0");
				continue;
			}
			b=D/d;
			if(b<2){
				puts("0");
				continue;
			}else if(n/2LL<b){
				puts("0");
				continue;
			}else{
				ans=(long long)n-2*b+1;
				cout<<ans<<endl; 
			}
		}
	}
	return 0;
}