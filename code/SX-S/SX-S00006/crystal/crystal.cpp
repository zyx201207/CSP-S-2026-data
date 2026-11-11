#include<bits/stdc++.h>
using namespace std;
long long n,m,a[500005];
int q(int x,int y){
	int s=a[x],sum=0;
	for(int i=1;i<=x;i++){
		int p=s-a[i];
		if(p<=y){
			sum++;
		}
	}
	return sum;
}
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	sort(a+1,a+n+1);
	int z=0;
	for(int i=1;i<=n;i++){
		int w=m;
		int e=q(i,w);
		z=max(z,e);
	}
	cout<<z;
	return 0;
}
