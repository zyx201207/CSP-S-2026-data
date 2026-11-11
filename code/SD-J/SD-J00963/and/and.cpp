#include<bits/stdc++.h>
using namespace std;
const int N=1e5+10;
int n,m,ans;
int a[N],k,j;
int f(int a){
	int m;
	while(a!=0){
		int t=a%2;
		m=m*10+t;
	}
	return m;
}
int he(int a,int b){
	k=f(a);
	j=f(b);
	int sum=0;
	for(int i=1;i<=n;i++){
		sum+=(k&j);
	}
	return sum;
}
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	for(int i=1;i<=n;i++){
		int l=i,r=i+m;
		for(;l<r;l++){
			ans=max(ans,he(a[l],a[r]));
		}
	}
	cout<<ans;
	return 0; 
}
