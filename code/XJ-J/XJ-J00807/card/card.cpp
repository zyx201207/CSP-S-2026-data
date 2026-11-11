#include<bits/stdc++.h>
using namespace std;
int a[10000001],b,e,f,d,g,h,k,n,m,sum;
string c[1000001];
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i]>>c[i];
	}
	if(n==1){
		cout<<0;
	}
	if(n==2){
		if(c[1]==c[2]){
			cout<<0;
		}else{
			cout<<n/2-min(a[1],a[2]);
		}
	}else{
		for(int i=1;i<=n/2;i++){
			if(c[i]!=c[n-i+1]){
				sum++;
			}
		}
		cout<<sum;
	}
	return 0;
}