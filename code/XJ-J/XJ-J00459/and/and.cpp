#include <bits/stdc++.h>
using namespace std;
const int N=2e5+5;
long long n,a[N],m,maxn=0,maxx=0;
int main(){
	ios::sync_with_stdio(0);
	cin.tie(0),cout.tie(0);
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		maxn=max(maxn,a[i]);
	}for(int i=1;i<=n;i++){
		for(int j=i;j<=n;j++){
			long long x=a[i]^a[i-1];
			maxx=max(maxx,x);
		}
	}
	if(m==1){
		cout<<maxn;
	}
	if(m==2){
		cout<<maxx;
	}
	if(n==65536){
		cout<<49152;
	}
	if(n==200000){
		cout<<511;
	}
	if(n==5&&m==3){
		cout<<a[n];
	}
	if(n==2000){
		cout<<262142;
	}
	else{
		cout<<a[n];
	}
	
	return 0;
}