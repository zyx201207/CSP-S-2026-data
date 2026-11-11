/*
Xi'an Aerospace City No.1 High School
Senior Grade 1
ZHANG Aoyi
SN-S00640

CCF CSP-S 2026
2026.10.31 14:30-18:30

The High School Affiliated to SNU
R#01-S#47

Answer Disk: D

This is the source code of [T1]
*/
#include<bits/stdc++.h>
using namespace std;
//priority_queue<int>q;
long long n,m;
long long a[500086];
long long c[500086];
long long cost;
int ans=0;
long long calc(int i,int j){
	return cost=a[i]*j-(c[i-1]-c[i-j-1]);
}
int find(long long ce,int end){
	int l=1,r=end;
	while(l<r){
		int mid=(l+r)/2;
		if(calc(end,end-(mid+1))<ce) r=mid;
		else l=mid+1;
	}
	return l;
}
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	sort(a+1,a+1+n);
	for(int i=1;i<=n;i++) c[i]=c[i-1]+a[i];
	for(int i=1;i<=n;i++){
		ans=max(ans,i-find(m,i));
	}
	cout<<ans;
	return 0;
}


