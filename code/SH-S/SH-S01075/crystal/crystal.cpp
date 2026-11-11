#include<bits/stdc++.h>
using namespace std;
long long n,m,a[100007];
__int128 b[100007];
__int128 nt;
int mx=1;
bool cmp(long long a,long long b){
	return a<b;
}
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	sort(a+1,a+1+n,cmp);
	for(int i=1;i<=n;i++) b[i]=b[i-1]+a[i];
	for(int i=0;i<n;i++){
		for(int j=i+1;j<=n;j++){
			__int128 x=(b[j]-b[i]+m+j-i-1)/(j-i);
			if(x>b[j]) mx=max(mx,j-i);
		}
	}
	cout<<mx;
	return 0;
}
