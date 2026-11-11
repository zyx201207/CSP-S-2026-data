#include<bits/stdc++.h>
using namespace std;
long long n,m;
long long a[100005];
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal,out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin>>n>>m;
	for(long long i=0;i<n;i++){
		cin>>a[i];
	}
	long long diff[100005];
	sort(a,a+n-1);
	for(long long i=0;i<n;i++){
		diff[i]=a[i+1]-a[i];
	}
	long long x[100005];
	for(int i=1;i<n;i++){
		x[i-1]=diff[i]+diff[i-1];
		if(diff[i]+x[i-1]==m){
			cout<<i+1;
			return 0;
		}
	}
	return 0;
} 
