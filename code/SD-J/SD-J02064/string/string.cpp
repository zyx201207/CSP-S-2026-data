#include<bits/stdc++.h>
using namespace std;
typedef unsigned long long ll;
ll n;
const ll N=2e5+1;
char a[N],c[N];
ll b[N];
ll sum=0,cnt=0;
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	ios::sync_with_stdio(false),cin.tie(0);
	cin>>n;
	cin>>b[1]>>a[1];
	for(int i=1;i<=b[1];i++){
		c[i]=a[1];
	}
	sum+=b[1];
	bool ok=0;
	for(ll i=2;i<=n;i++){
		cin>>b[i]>>a[i];
		for(ll j=sum+1;j<=sum+b[i-1];j++){
			c[j]=a[i];
		}
		if(a[i]!=a[i-1]) ok=1;
		sum+=b[i];
	}
	if(ok==0){
		cout<<0;
		return 0;
	}
	for(ll i=1;i<=sum/2;i++){
		if(c[i]!=c[sum+1-i]) cnt++;
	}
	cout<<cnt;
	return 0;
}
 


