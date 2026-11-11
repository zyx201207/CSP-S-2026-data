#include<bits/stdc++.h>
using namespace std;
int a[2000009],b[2000009];
int n,m;
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
	int maxn=-1;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		if(a[i]>maxn){
			maxn=a[i];
		}
	}
	cout<<maxn;
	int x=0,y=0,k=0,q=10;
	for(int i=1;i<=n;i++){
		for(int j=1;j<=m;j++){
			if(j<=n-m){
				b[k]=a[j];
				k++;
			}
		}
	}
	for(int j=0;j<k;j++){
		int w=b[j];
		if(j<k){
			int e=b[j+1];
		}
		while(w!=0){
			x=x+w%2*q;
			w/=2; 
			q*=10;
		}
		q=10;
		while(e!=0){
			x=x+w%2*q;
			w/=2; 
			q*=10;
		}
	}
}
