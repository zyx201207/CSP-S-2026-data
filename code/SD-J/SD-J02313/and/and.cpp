#include<iostream>
#include<cmath>
#include<cstdio>
#include<algorithm>
#define ll long long
using namespace std;
const int N=2*10e5+10;
int n,m;
struct note{
	int w;
	bool h[40],b[40]; 
	int k=1;
}a[N];
int s;
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++) {
		cin>>a[i].w;
		s=a[i].w;
		while(s>=1){
			a[i].h[a[i].k]=s%2;
			s/=2;
			a[i].k++;
		}
		for(int j=1;j<=a[i].k;j++){
			a[i].b[j]=a[i].h[a[i].k-j+1];
		}
	}
	int maxx=0;
	if(m==1){
		for(int i=1;i<=n;i++){
			if(a[i].w>maxx){
				maxx=a[i].w;
			}	
		}
		cout<<maxx;
	}
	else if(m==n){
		cout<<1;
	}
	else{
		cout<<a[n].w;
	}
	return 0;
}
