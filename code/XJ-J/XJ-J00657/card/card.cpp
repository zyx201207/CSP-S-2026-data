#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int maxn=2e5+10;
map<ll,ll>mm;
ll n;
ll m;
int a[maxn];
int main(){
	cin>>n>>m;
	ll t=1;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	//while(t++){
		if(t==n){
			//break;
		}
		ll b[maxn];
		int x=0;
		for(int i=t;i<=n;i++){
			for(int j=1;j<=x;j++){
				if(b[j]==a[i]){
					cout<<b[j]<<endl;
					x=x-j;
				}
			}
			x++;
			b[x]=a[i];
		}
		for(int i=1;i<=x;i++){
			cout<<b[x];
		}
	//}
	return 0;
}
