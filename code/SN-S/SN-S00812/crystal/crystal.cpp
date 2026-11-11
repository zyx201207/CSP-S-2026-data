#include<bits/stdc++.h>
using namespace std;
long long n,m;
long long v=0;
long long a[500001]; 
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	long long l=1;
	__int128 u=0;
	sort(a+1,a+1+n); 
	for(int r=1;r<=n;r++){
		u+=a[r];
		while(a[r]*(r-l+1)-u>m&&l<=r){
			l++;
			u-=a[l-1];
		}
		v=max(v,r-l+1);
	}
	cout<<v;
	return 0;
}
