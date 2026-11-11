#include<bits/stdc++.h>
using namespace std;
const int N=5e5;
long long a[N+10],t[N+10];
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","r",stdout);
	long long n,m,mx=0,k;
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		t[a[i]]++;
	}
	for(int i=1;i<=N;i++){
		if(t[i]>mx){
			mx=t[i];
			k=i;
		}
	}
	for(int i=1;i<=n;i++) a[i]=k-a[i];
	sort(a+1,a+n+1);
	for(int i=1;i<=n;i++){
		if(m<a[i]) break;
		if(a[i]>0){
			m-=a[i];
			a[i]=0;
			mx++;
		}
		if(a[i]==0) k=i;
	}
	if(m>0){
		for(int i=k;i>=1;i--){
			if(a[i]<0&&abs((a[i]-a[i+1])*mx)<=m){
				m-=abs(a[i]*mx);
				mx++;
			}
		}
	}
	cout<<mx;
	return 0;
}
