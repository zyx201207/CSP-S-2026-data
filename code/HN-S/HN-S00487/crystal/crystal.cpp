#include<bits/stdc++.h>
using namespace std;
int n,m,a[500005],q[500005];
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		if(i!=1)q[i]=q[i-1]+abs(a[i]-a[i-1]);
	}for(int i=1;i<=n;i++){
		if(q[i]==m){
			cout<<i;
			return 0;
		}else if(q[i]>m){
			cout<<i-1;
			return 0;
		} 
	}cout<<n; 
	return 0;
} 
