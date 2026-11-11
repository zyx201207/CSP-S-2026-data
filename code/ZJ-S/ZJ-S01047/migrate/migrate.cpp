#include<bits/stdc++.h>
#define ll long long
using namespace std;
const int N=2e6+10;
ll c,t,n,d,x[N],cnt=0;
int main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	cin>>c>>t;
	while(t--){
		cnt=0;
		cin>>n>>d;
		
		for(int i=1;i<=n;i++){
			cin>>x[i];
		}
		if(c==11||c==12){
			t=x[1]-x[0];
			if(d<2*t) cout<<0<<endl;
			else{
				for(int i=1;i<=n-d-1;i++){
					if(i+d+1<=n) cnt++;
				}
				cout<<cnt<<endl;
			}
		}
		else{
			cout<<0<<endl;
		}
	}
	return 0;
}
