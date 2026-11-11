#include<bits/stdc++.h>
using namespace std;
int n,m,a[200005];
int And(int x,int y){
	int X[35],Y[35],ans;
	int x_=0,y_=0;//x_:x长度 
	while(x){
		X[++x_]=x%2;
		x/=2;
	}
	while(y){
		Y[++y_]=y%2;
		y/=2;
	}
	for(int i=1;i<=max(x_,y_);i++){
		ans+=(X[i]&&Y[i])*pow(2,i-1);
	}
	return ans;
}
int f(int tans,int x,int y){//tans:目前的答案 x:已经选了的数量 y:在(y,n-(m-x)+1)中选数 
	int mx=0;
	if(x==m)return tans;
	for(int i=y;i<=n-m+x+1;i++){
		cout<<mx<<" ";
		mx=max(mx,f(And(tans,a[i]),x+1,i+1)); 
	}
	cout<<"\n";
	return mx;
}
int main(){
	//freopen("and.in","r",stdin);
	//freopen("and.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	if(m==1){
		int mx=0;
		for(int i=1;i<=n;i++){
			mx=max(mx,a[i]);
		}
		cout<<mx;
		return 0;
	}
	if(m==n){
		int ans=a[1];
		for(int i=2;i<=n;i++){
			ans=And(ans,a[i]);
		}
		cout<<ans;
		return 0;
	}
	if(m==2){
		int mx=0;
		for(int i=1;i<n;i++){
			for(int j=i+1;j<=n;j++){
				mx=max(mx,And(a[i],a[j]));
			}
		}
		cout<<mx;
		return 0;
	}
	else{
		int mx=0;
		for(int i=1;i<=n;i++){
			mx=max(mx,a[i]);
		}
		cout<<mx;
		return 0;
	}
	//cout<<f(pow(2,30)-1,0,1);
	return 0;
}
