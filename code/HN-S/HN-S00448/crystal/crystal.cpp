#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	long long n,m,d=0;
	cin>>n>>m;
	long long a[n]={0},b=0;
	for(int q=0;q<n;q++){
		cin>>a[q];
	}
	for(int q=0;q<n;q++){
		for(int w=0;w<n;w++){
			if(a[w]>a[w-1]){
				long long e=a[w];
				a[w]=a[w-1];
				a[w-1]=e;
			}
		}
	}
	for(int q=0;q<n;q++){
		for(int w=q+1;w<n;w++){
			long long e=-10000000000000000000000000000000000000;
			b=0;
			for(int r=w;r<n;r++){
				e=(e>a[r])?e:a[r];
			}
			for(int r=w;r<n;r++){
				b+=e-a[r];
			}
			d=(b<m&&(w-q)*e>d)?(w-q)*e:d;
		}
	}
	cout<<d;
	return 0;
}
