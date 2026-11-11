#include <bits/stdc++.h>
using namespace std;
int main(){
	freopen("card.in","r","stdin");
	freopen("card.out","w","stdout");
	int n,m;
	cin>>n>>m;
	int a[1000000]={}
	for(int i=0;i<n;i++){
		cin>>a[i];
	}
	int b[1000000];
	for(int i=0;i<n;i++){
		b[i]+=a[i];
		if(b[i]=a[i] or b[i]=a[i]+a[i+1]){
			cout<<1;
		}
	}
return o;
}