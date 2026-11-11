#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
ll n,m,ans=0;
const ll maxn=5e5+10;
int a[maxn];
int main(){
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	sort(a+1,a+n+1);
	ll diff=a[2]-a[1];
	ll cnt=m/(2*diff);
	if(n==1){
		cout<<1;
		return 0;
	}
	if(n%2==0){
		for(int i=1;i<=n;i++){
			if(cnt-i>=0){
				ans++;
			}else{
				break;
			}
		}
		cout<<ans*2+2;
		return 0;
	}
	if(n%2==1){
		for(int i=1;i<=n;i++){
			if(cnt-i>=0){
				ans++;
			}else{
				break;
			}
		}
		cout<<ans*2+1;
		return 0;
	}
	return 0;
}

















