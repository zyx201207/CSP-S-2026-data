#include<bits/stdc++.h>
using namespace std;
const int N=2e6+5;
long long c,t,n,d,k,x[N],ans;
int main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin>>c>>t;
	while(t--){
		cin>>n>>d;
		for(int i=1;i<=n;i++){
			cin>>x[i];
		}
		k=x[n]-x[n-1];
		for(int i=1;i<=t;i++){
			if(k%i==1){
				ans+=1;
			}
		}
		cout<<n-1;
	}
	return 0;
}
