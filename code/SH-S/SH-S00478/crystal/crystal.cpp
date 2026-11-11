#include<bits/stdc++.h>
using namespace std;
#define ll long long
ll n;
ll m;
ll a[(int)1e6];
ll b[(int)1e6];
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	//ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	cin>>n>>m;
	for(int i=0;i<n;i++){
		cin>>a[i];
	}
	ll average;
	for(int i=0;i<n;i++){
		average+=a[i];
		average/=n;
	}
	ll min[2];
	min[0]=abs(a[0]-average);
	min[1]=0;
	for(int i=1;i<n;i++){
		if(abs(a[i]-average)<min[0]){
			min[0]=abs(a[i]-average);
			min[1]=i;
		}
	}
	ll x=a[min[1]];
	ll idx=0;
	for(int i=0;i<n;i++){
		b[i]=abs(x-a[i]);
	}
	sort(b,b+n);
	for(int i=0;i<n;i++){
		if(b[i]<=m){
			m-=b[i];
			idx++;
		}
	}
	cout<<idx<<endl;
	return 0;
} 
