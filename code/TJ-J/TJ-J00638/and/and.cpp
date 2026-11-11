#include<bits/stdc++.h>
using namespace std;
int a[200005];
int b[200005];
int iten(int x){
	int res=1;
	for(int i=1;i<=x;i++){
		res*=10;
	}
	return res;
}
int itt(int x){
	int t=1;
	int res=0;
	while(x){
		res+=iten(t-1)*(x%2);
		t++;
		x/=2;
	}
	
	return res;
}
int lon(int x){
	for(int i=1;;i++){
		x/=10;
		if(x<1) return i; 
	}
}
int iand(int x,int y){
	int res=0;
	int lon1=lon(x),lon2=lon(y);
	for(int i=0;i<max(lon1,lon2);i++){
		if(x%10==1&&y%10==1){
			res+=iten(i);	
		}
		x/=10,y/=10;
	}
	return res;
}
int iba(int x){
	int res=0;
	int twoo=1;
	int lo=lon(x);
	for(int i=1;i<=lo;i++){
		res+=twoo*(x%2);
		twoo*=2;
		x/=10;
	}
	return res;
}
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	int n,m;
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	sort(a+1,a+n+1);
	if(m==1){
		cout<<a[n];
		return 0;
	}
	int ans=0;
	if(m==2){
		for(int i=1;i<n;i++){
			for(int j=i+1;j<=n;j++){
				if(ans<iand(itt(a[i]),itt(a[j]))){
					ans=iand(itt(a[i]),itt(a[j]));
				}
			} 
		}
		cout<<iba(ans);
		return 0;
	}
	cout<<a[n-m+1];
	return 0;
}











