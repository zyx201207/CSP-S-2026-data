#include<bits/stdc++.h>
using namespace std;
int a[78911145];
int sb(int x,int y){
	int k=0,t=1;
	while(x&&y){
		if(x%2==y%2&&x%2==1){
			k+=t;
		}
		t*=2;
		x/=2;
		y/=2;
	} 
	return k;
} 
int main(){
	int n,mx=-1;
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	for(int i=1;i<=n;i++){
		for(int j=i+1;j<=n;j++){
			mx=max(mx,sb(a[i],a[j]));
		}
	}
	cout<<mx;
	return 0;
}
