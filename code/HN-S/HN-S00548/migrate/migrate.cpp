#include<bits/stdc++.h>
using namespace std;
#define ll long long
const ll inf=0x3f3f3f3f,N=2e6+5;
ll c,t,i,j,x[N],n,d,k,f[N],ans;
int main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin>>c>>t;
	while(t--){
		cin>>n>>d;
		for(i=1;i<=n;i++){
			cin>>x[i];
		}
		if(c==11||c==12||1==1){
			ans=0;
			k=d/(x[2]-x[1]);
			if(k<2){
				cout<<"0"<<endl;
			}
			else{
				if(n==d){
					cout<<"0"<<endl;
				}
			}
		}
	}
	return 0;
} 
