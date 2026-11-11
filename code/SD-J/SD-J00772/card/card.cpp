#include<bits/stdc++.h>
using namespace std;
int main(){
	long long n,m,a[10000],r[10000][100000]={0};
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	for(int i=1;i<=n;i++){
		for(int j=i;j<=n;j++){
			r[i][j]=a[j];
		}
	}
	for(int i=1;i<=n;i++){
		for(int s=i;s<=n;i++){
			for(int j=i;j<=n;j++){
			if(r[i][s]==r[i][j]){
				for(int x=s;x<j;x++){
					r[i][x]=0;
				}
			}
			}
	}
	}
	long long x[1000]={0};
	for(int i=1;i<=n;i++){
		for(int j=i;j<=n;j++){
			if(r[i][j]!=0)x[r[i][j]]++;
		}
	}
	for(int i=1;i<=n;i++){
		if(x[i]!=0)cout<<x[i];
	}
}
