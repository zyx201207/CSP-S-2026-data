#include<bits/stdc++.h>
using namespace std;
const int N=5e5+5;
long long a[N],s[N];
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	long long n,m;
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		a[i]+=1e12;
	}
	sort(a+1,a+1+n);
	for(int i=1;i<=n;i++){
		s[i]=s[i-1]+a[i];
	}
	int l=1,r=1,mx=-1;
	while(r<=n){
		long long sum=s[r]-s[l-1];
		while(a[r]*(r-l+1)-sum>m) l++;
		mx=max(mx,r-l+1);
		r++;
	}	
	cout<<mx;
	return 0;
} 