#include<bits/stdc++.h>
using namespace std;
long long a[500010];
long long aa[500010];
int n,l=1,r,c=1;
long long k; 
bool ch(int x){
	for(int i=x;i<=n;i++){
		if(a[i]*x-(aa[i]-aa[i-x])<=k) return 1;
	}
	return 0;
}
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>k;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	sort(a+1,a+n+1);
	for(int i=1;i<=n;i++){
		aa[i]=aa[i-1]+a[i];
	}
	r=n;
	while(l<=r){
		int op=(l+r)/2;
		if(ch(op)){
			c=op;
			l=op+1;
		}
		else{
			r=op-1;
		}
	}
	cout<<c;
	return 0;
} 
