#include<bits/stdc++.h>
using namespace std;
#define ll long long

ll arr[500005];
ll arr2[500005];
ll n,m;
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>arr[i];
	}
	if (n>5000){
		ll sum=1;
		ll l=m;
		ll j=n-1;
		while(l-(arr[n]-arr[j])>=0&&j>0){
			sum++;
			l-=(arr[n]-arr[j]);
			j--;
		}
		cout<<sum;
		return 0;
	}
	sort(arr+1,arr+1+n);
	
	
	ll out=-1;
	
	for(int i=n;i>=2;i--){
		ll sum=1;
		ll l=m;
		ll j=i-1;
		while(l-(arr[i]-arr[j])>=0&&j>0){
			sum++;
			l-=(arr[i]-arr[j]);
			j--;
		}
		//cout<<sum<<' ';
		out=max(out,sum);
		//cout<<out<<' ';
	}
	cout<<out;
	return 0;
} 
