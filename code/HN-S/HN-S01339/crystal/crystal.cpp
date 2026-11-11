#include<bits/stdc++.h>
#define ll long long
using namespace std;
ll n,m,a[500080],s[500080],maxx=-1;
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	bool bo=0,bo1=0;
	ll mm;
	for(int i=0;i<n;i++){
		cin>>a[i];
		if(i>0&&a[i]!=i+1){
			bo=1;
		}
		if(i>1&&(a[i]-a[i-1])!=(a[i-1]-a[i-2])){
			bo1=1;
		}
	}
	if(bo==0){
		int j=1,js=0;
		while(m>=0){
			m=m-j;
			js++;
			j++;
		}
		cout<<js;
		return 0;
	}
	if(bo1==0){
		int j=a[1]-a[0],js=0;
		while(m>=0){
			m=m-j;
			js++;
			j+=a[1]-a[0];
		}
		cout<<js;		
		return 0;
	}
	sort(a+0,a+n);
	for(ll i=0;i<n;i++){
		ll k=i+1,num=0;
		while(num<=m&&k<=n&&a[k]-a[i]<=m){
			num+=(a[k]-a[k-1])*(k-i);
			k++;
		}
		maxx=max(maxx,k-i-1);
	}
	cout<<maxx<<endl;
	return 0;
}



