#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
string c;
ll a[200005],n,L=0,ans=0;
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	for(ll i=1;i<=n;i++){
		cin>>a[i]>>c[i];
		L+=a[i];
	}
	for(ll i=1;i<=L/2;i++){
		char x,y;
		ll p=i,q=L+1-i;
		for(ll j=1;j<=n;j++){
			if(p>a[j])p-=a[j];
			else x=c[j];
		}
		for(ll j=n;j>=1;j--){
			if(q<L-a[j]+1){
				q+=a[j];
			}
			else y=c[j];
		}
		if(x!=y)ans++;
	}
	cout<<ans;
	fclose(stdin);
	fclose(stdout);
	return 0;
}
