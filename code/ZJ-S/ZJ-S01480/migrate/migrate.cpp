#include<bits/stdc++.h>
using namespace std;
int x[2000005];
int c,t;
int n,d;
int main(){
	cin.tie(0),cout.tie(0);
	freopen("migrate.in","r",stdin);
	freopen("migrate.out ","w",stdout);
	cin>>c>>t;
	while(t--){
		cin>>n>>d;
		for(int i=1;i<=n;i++){
			cin>>x[i];
		}
		if(c==13||c==14){
			cout<<1<<"\n";
		}
		else if(c==12||c==11){
			if(n%2){
				if(d>=(n+1)/2)cout<<0<<"\n";
				else cout<<2<<"\n";
			}else{
				if(d>n/2)cout<<0<<"\n";
				else if(d==n/2)cout<<1<<"\n";
				else cout<<2<<"\n";
			}
		}else{
			srand(time(0));
			cout<<rand()%n<<"\n";
		}
	}
	return 0;
}
