#include<bits/stdc++.h>
#define ll long long
using namespace std;
ll n,m,a[500050],d[500050];
bool flag=0;
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	ll k=a[2]-a[1];
	for(int i=2;i<=n;i++){
		if(a[i]-a[i-1]!=k) flag=1;
	}
	if(flag==0){
		ll i=a[1],pos=1;
		while(m>=i){
			m-=i;
			i+=k;
			pos++;
		}
		cout<<pos;
		return 0;
	}
	return 0;
}
