#include<bits/stdc++.h>
using namespace std;
#define ll long long
ll ar[100000000000];
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	int a,b;
	ll l=0,n=0,d=0;
	cin>>a>>b;
	for(int i=1;i<=a;i++){
		cin>>ar[i];
	}
	for(int i=1;i<=a;i++){
		l=ar[i] and ar[i+1];
		d=max(l,n);
		n=l;
	}
	cout<<d;
	return 0;
}
