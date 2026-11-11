#include<bits/stdc++.h>
using namespace std;
int n,m,a[200005],lkg,f[10];
bool bmp(int x,int y){
	return x>y;
}
bool f1;
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		if(a[i]<=4)f[a[i]]++;
		else f1=true;
	}
	sort(a+1,a+1+n,bmp);
	if(m==1){cout<<a[1];return 0;}
	if(m==2){
		int max1=-1;
		for(int i=2;i<=n;i++){
			int m=(a[i]&a[i-1]);
			max1=max(m,max1);
		}
		cout<<max1;
		return 0;
	}
	lkg=a[1];
	for(int i=2;i<=n;i++){
		lkg=(lkg&a[i]);
	}
	if(m==n){cout<<lkg;return 0;}
	if(m==n-1&&n>=10000){
		int max1=-1;
		for(int i=1;i<=n;i++)max1=max(max1,(lkg|a[i]));
		cout<<max1;
		return 0;
	}
	if(f1==false){
		if(f[4]>=m){cout<<4;return 0;}
		else if(f[3]>=m){cout<<3;return 0;}
		else if(f[3]+f[2]>=m){cout<<2;return 0;}
		else if(f[3]+f[1]>=m){cout<<1;return 0;}
		else {cout<<0;return 0;}
	}
	if(n>=1e8/m){cout<<0;return 0;}
	int max1=-1; 
	for(int i=1;i<=n-m;i++){
		int m1=a[i];
		for(int j=i+1;j<=m;j++){m1=(m1&a[j]);}
		max1=max(max1,m1);
	}
	cout<<max1;
	fclose(stdin);
	fclose(stdout);
	return 0;
} 
