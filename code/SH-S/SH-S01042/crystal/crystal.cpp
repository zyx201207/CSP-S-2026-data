#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
ll n,m,a[500005];
bool cmp(int x,int y){
	return x<y;
}
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	for(ll i=1;i<=n;i++){
		cin>>a[i];
	}
	sort(a+1,a+n+1,cmp); 
	ll ans1=1,req1=0,num1=m;
	for(ll i=n-1;i>=1;i--){
		req1=a[n]-a[i];
		if(num1>=req1){
			ans1++;
			num1-=req1;
		}
		else break;
	}
	ll ans2=1,req2=0,num2=m;
	for(ll i=2;i<=n;i++){
		req2=a[i]-a[i-1];
		if(num2>=req2){
			ans2++;
			num2-=req2*(i-1);
		}
		else break;
	}
	cout<<max(ans1,ans2);
	return 0;
} 
