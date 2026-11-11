#include<bits/stdc++.h>
#define ll long long
#define INF 0x3f3f3f3f
using namespace std;
const int N=5e5+10;
ll a[N],m,n,b[N];
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	cin>>n>>m;
	ll c[m+1];
	memset(c,0,sizeof c);
	for(ll i=1;i<=n;i++){
		cin>>a[i];
	}
	for(ll i=1;i<=n;i++){
		memset(b,0,sizeof b);
		ll back=1;
		for(int j=i;j<=n;j++){
			ll reback=back;
			b[reback]=a[j];
			for(int x=1;x<back;x++){
				if(b[x]==b[back]){
					back=x-1;
					break;
				}
			}
			if(reback!=back) b[++back]=b[reback];
		    back++;
		}
		for(int j=1;j<back;j++){
			c[b[j]]++;
		}
    }
    for(int i=1;i<=m;i++) cout<<c[i]<<" ";
	return 0;
}