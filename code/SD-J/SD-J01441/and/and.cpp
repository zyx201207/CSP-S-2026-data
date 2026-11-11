#include<bits/stdc++.h>
using namespace std;
long long a[200005],n,m,b;
int z;
int f(int x,int t){
	if(x>=n){
		return 0;
	}
	
	b&=a[x];
	if(t<m){
		f(x+1,t+1);
	}
	
	return b;
}
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
	for(int i=0;i<n;i++){
		cin>>a[i];
	}
	if(m==1){
		sort(a,a+n);
		cout<<a[n-1];
		return 0;
	}
	for(int i=0;i<n;i++){
		for(int j=i+1;j<n;j++){
			b=a[i]&a[j];
			z=max(f(j+1,2),z);
			b=0;
		}
	}
	cout<<z;
	return 0;
}
