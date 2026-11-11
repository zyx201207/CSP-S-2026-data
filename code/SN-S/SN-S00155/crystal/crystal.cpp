#include<bits/stdc++.h>
#define ll long long
using namespace std;
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	ios::sync_with_stdio(false),cin.tie(0),cout.tie(0);
	ll n,m,num=0,sum=0,ave,cha,she=0,a[100010],b[100010];
	cin>>n>>m;
	for(ll i=0;i<n;i++){
		cin>>a[i]; 
	}
	for(ll i=0;i<n;i++){
		for(ll j=i+1;j<n;j++){
			if(a[i]>a[j]){
				cha=a[i];
				a[i]=a[j];
				a[j]=cha;
			}
			if(a[i]==a[j]){
				she=1;
			}
		}
	}
	
	for(ll i=1;i<n;i++){
		for(ll j=2;j<=i+1;j++){
			ave=a[i];
			for(ll k=1;k<j;k++){
				ave+=a[i-k];
			}
			if(a[i]*j==ave+m){
				b[num]=j;
			}
			num++;
		}
	}
	for(ll i=0;i<n;i++){
		if(b[i]>sum){
			sum=b[i];
		}
	}
	cout<<sum+she;
	return 0;
}
