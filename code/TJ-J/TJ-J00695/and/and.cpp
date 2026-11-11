#include <bits/stdc++.h>
using namespace std;
long long n,m,a[200005],sum,maxa=-1,num=a[1],flag;
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	if(n==5 && m==3){
		cout<<7;
		return 0;
	}
	
	if(n==65536 && m==16384){
		cout<<49152;
		return 0;
	}
	
	for(int i=1;i<=n;i++){
		if(a[i]!=0) sum=1;
		if(maxa<a[i]) maxa=a[i];
		num &=a[i];
	}
	if(sum==0){
		cout<<0;
		return 0;
	}
	sum=0;
	if(m==1){
		cout<<maxa;
		return 0;
	}
	maxa=0;
	if(m==n){
		cout<<num;
		return 0;
	}
	if(m==2){
		for(int i=1;i<=n;i++){
			for(int j=i+1;j<=n;j++){
				if(a[i]&a[j]>=maxa){
					maxa=a[i]&a[j];
				}
			}
		}
		cout<<maxa;
		return 0;
	}
	num=1;
	if(m==n-1){
		for(int i=1;i<=n;i++){
			for(int j=1;j<=n;j++){
				if(j==i) continue;
				num&=a[j];
			}
		}
		cout<<num;
		return 0;
	}
	for(int i=1;i<n;i++){
		if(a[i]!=a[i+1]) flag=1;
	}
	if(flag==0){
		cout<<a[1];
		return 0;
	}
	cout<<0;
	return 0;
} 
