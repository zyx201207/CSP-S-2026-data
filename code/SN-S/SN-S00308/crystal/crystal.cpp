#include<bits/stdc++.h>
using namespace std;

long long n,m,a[500010];
long long s[500010];

bool check(int k){
	if(k>n)
		return 0;
	long long res=0;
	for(int i=1;i<=k;i++)
		res+=s[i]*i;
	if(res<=m)
		return 1;
	for(int i=k+1;i<=n;i++){
		res-=a[i]-a[i-k];
		res+=k*s[i];
		if(res<=m)
			return 1;
	}
	return 0;
}

int find(){
	int l=-1,r=500010;
	while(l+1<r){
		int mid=(l+r)/2;
		if(check(mid)) l=mid;
		else r=mid;
	}
	return l;
}

int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++)
		cin>>a[i];
	for(int i=1;i<n;i++)
		s[i]=a[i+1]-a[i];
	cout<<find()+1;
	return 0;
}
