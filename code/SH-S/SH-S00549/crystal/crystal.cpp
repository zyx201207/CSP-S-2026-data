#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N=500009;
ll n,m,a[N],ans;
ll flag=1,flag2=1,cha;
void solveBF(){
	sort(a+1,a+n+1);
	ll now,m1;
	for(ll i=1;i<=n;i++){
		now=0;
		m1=m;
		for(ll j=i;j>=1;j--){
			if(m1>=a[i]-a[j]){
				now++;
				m1-=a[i]-a[j];
			}else{
				break;
			}
		}
		ans=max(now,ans);
	}
	cout<<ans;
}
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	for(ll i=1;i<=n;i++){
		cin>>a[i];
		if(a[i]!=i) flag=0;
		if(i>2){
			if(a[i]-a[i-1]!=cha){
				flag2=0;
			}
		}
		if(i==2){
			cha=a[2]-a[1];
		}
	}
	if(n<=5000){
		solveBF();
		return 0;
	}
	if(flag){
		ans=1;
		ll now=0;
		for(ll i=1;i<n;i++){
			if(now+=i<=m){
				ans++;
				now+=i;
			}
		}
		cout<<ans;
		return 0; 
	}
	if(flag2){
		ans=1;
		ll now=0;
		for(ll i=cha;i<n;i+=cha){
			if(now+i<=m){
				ans++;
				now+=i;
			}
		}
		cout<<ans;
		return 0;
	}
} 
