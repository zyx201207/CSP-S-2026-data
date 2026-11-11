#include<bits/stdc++.h>
using namespace std;
long long a,b,n[500000],c[500000];
int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>a>>b;
	for(long long i=0;i<a;i++){
		cin>>n[i];
	}
	sort(n,n+a-1);
	for(long long i=1;i<a;i++){
		c[i]=c[i-1]+n[i]-n[i-1];
		if(c[i]>b){
			cout<<i;
			return 0;
		}
	}
	return 0;
} 
