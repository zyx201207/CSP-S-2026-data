#include<bits/stdc++.h>
using namespace std;
#define int long long
int n,m;
int a[514514];
int xx;
int ans=0;
bool pd(int x,int y){
	return x>y;
}
signed main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	for(int i=0;i<n;i++){
		cin>>a[i];
	}
	sort(a,a+n);
	vector<int>ls(n+5);
	for(int i=0;i<m;i++){
		ls[a[i]+1]++;
	}
	if(n>=m)for(int i=m;i<m+(n-m);i++)ls[a[i]]++;
	sort(ls.begin(),ls.end(),pd);
	int maxn=ls[0];
	xx=a[(int)ceil(n/2)];
	int f=(int)ceil(n/2);
	for(int i=(int)ceil(n/2);i<n;i++){
		if(a[i]==xx)f=i;
	}
	for(int i=0;i<=f;i++){
		if(xx-a[i]<=m){
			ans++;
			m-=(xx-a[i]);
		}
	}
	cout<<max(ans,maxn);
	return 0;
}