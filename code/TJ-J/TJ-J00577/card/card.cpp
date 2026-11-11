#include <bits/stdc++.h>
#define ll long long
using namespace std;
ll n,m;
const int N=3e5+4;
ll t[N];
ll a[N];
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	cin>>n>>m;
	for(ll i=1;i<=n;i++){
		scanf("%lld",&a[i]);
	}
	vector<ll>v(n+1);
	for(ll i=1;i<=n;i++){
		for(ll j=i;j<=n;j++){
			int pos=-1;
			for(ll z=i;z<j;z++){
				if(v[z]==a[j]){
					pos=z;
					break;
				}
			}
			if(pos==-1){
				v[j]=a[j];
			}else{
				for(int z=pos;z<j;z++)v[z]=0;
				v[j]=a[j];
				
			}
		} 
		for(int j=i;j<=n;j++)t[v[j]]++;
	}
	for(int i=1;i<=m;i++){
		printf("%lld ",t[i]);
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}
