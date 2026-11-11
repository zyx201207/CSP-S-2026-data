#include<bits/stdc++.h>
using namespace std;
int n,m,a[1000000],mx,sum=a[1]&a[2];
void check(int r,int l,int j){
	if(j>2){
		check(r+1,l+1,j-1);
		//cout<<sum<<endl;
	}
	if(l>n) return;
	if(j<=2){
		for(int i=r+1;i<=n;i++){
			mx=max(mx,a[r]&a[i]);
			//cout<<r<<' '<<i<<' '<<j<<' '<<mx<<endl;
		}
	}
	if(j>2){
		mx=max(a[r]&sum,mx);
		//cout<<r<<' '<<l<<' '<<j<<' '<<mx<<endl;
	}
	sum=mx;
	check(r+1,l+1,j);
	return;
}
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	check(1,2,m);
	cout<<mx;
	fclose(stdin);
	fclose(stdout);
	return 0;
}
