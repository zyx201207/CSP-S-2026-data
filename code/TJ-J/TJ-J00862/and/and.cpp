#include <bits/stdc++.h>
using namespace std;
long long aand(int x,int y){
	string xs[30];
	string ys[30];
	int ans[30];
	int i=0;
	while(x!=0){
		xs[i]=x%2;
		x/=2;
		i++;
	}
	while(y!=0){
		ys[i]=y%2;
		y/=2;
		i++;
	}
	for(int i=0;i<30;i++){
		string t=xs[i];
		xs[i]=xs[30-1-i];
		xs[30-1-i]=t;
	}
	for(int i=0;i<30;i++){
		string t=ys[i];
		ys[i]=ys[30-1-i];
		ys[30-1-i]=t;
	}
	for(int i=0;i<30;i++){
		if(xs[i]=="1"&&ys[i]=="1"){
			ans[i]=1;
		}else{
			ans[i]=0;
		}
	}
	long long sum;
	for(int i=0;i<30;i++){
		sum+=ans[i]*pow(2,i);
	}
	return sum;
}
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	int n,m,maxa=0;
	cin>>n>>m;
	int a[n];
	for(int i=0;i<n;i++){
		cin>>a[i];
	}
	for(int i=0;i<n;i++){
		for(long long j=0;j<n;j++){
			maxa=aand(a[i],a[j]);
		}
	}
	cout<<maxa;
	return 0;
} 
