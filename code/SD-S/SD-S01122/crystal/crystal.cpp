#include<bits/stdc++.h>
#define ll long long
using namespace std;
const int N=5e5+5;
int n;
ll m;
ll a[N];
ll ans;
bool flagA=1,flagB=1;
int cha; 
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		if(i==2){
			cha=a[i]-a[i-1];
		}
		if(a[i]!=i){
			flagA=0;
		}
		if(a[i]-a[i-1]!=cha){
			flagB=0;
		}
	}
	sort(a+1,a+n+1);
	for(int i=((flagA||flagB)?n:1);i<=n;i++){
		ll res=1,k=m;
		for(int j=i-1;j>=1;j--){
			if(k>=(a[i]-a[j])){
				res++;
				k-=(a[i]-a[j]);
			}
			else{
				break;
			}
		}
		ans=max(ans,res);
	}
	cout<<ans;
	return 0;
}
