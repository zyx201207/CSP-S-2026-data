#include<bits/stdc++.h>
using namespace std;
using ull = unsigned long long;
int b[500005];
int main(){
	freopen("crystal.in ","r",stdin);
	freopen("crystal.out ","w",stdout);
	ull n,m,maxx=0;
	cin>>n>>m;
	int a[500005];
	for(int i=1;i<=n;i++){
		cin>>a[i];
		b[i]=b[i-1]+a[i];
	}
	sort(a+1,a+n+1);
	
	ull i=1,j=1;
	ull x=a[1];
	while(i<=n && j<=n){
		ull target = a[i]*(i-j+1);
		if(target-x<=m) {
			i++;
			x+=a[i];
		}
		else {
			maxx=max(maxx,i-j);
			x-=a[j];
			j++;
		}
	}
	cout<<maxx;
	return 0;
}
