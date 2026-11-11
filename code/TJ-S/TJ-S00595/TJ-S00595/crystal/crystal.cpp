#include <bits/stdc++.h>
using namespace std;
long long n,m,a[500005];
long long g,h,ge,ma;
bool dx(){
	long long x=a[1]-a[0];
	for(int i=1;i<n;i++){
		if(a[i]-a[i-1]!=x) return 0;
	}
	return 1;
}
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	for(int i=0;i<n;i++){
		cin>>a[i];
	}
	if(n==1){
		cout<<1;
		return 0;
	}
	if(n==2){
		if(abs(a[1]-a[0])>m) cout<<1;
		else cout<<2;
		return 0;
	}
	sort(a,a+n);
	if(dx()){
		ge=a[1]-a[0];
		while(h<m){
			h+=ge*g;
			g++;
		}
		cout<<g;
	}
	else{
		for(int i=1;i<n;i++){
			g=0,h=0;
			while(h<m&&g<=i){
				if(a[i]-a[i-g]>m) break;
				h+=a[i]-a[i-g];
				if(h>m) break;
				if(h==m){g++;break;}
				g++;
			}
			ma=max(ma,g);
		}
		cout<<ma;
	}
	return 0;
}
