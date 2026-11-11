#include<bits/stdc++.h>
using namespace std;
const int N=1e6;
int a[N];
/*bool f(int l,int r,int n){
	int z=0;
	for(int i=1+1;i<=n;i++){
		if(a[i]>1&&a[i]<r) z++;
	}
	return z>=2;
}*/
int main(){
	int c,t,k=0;
	cin>>c>>t;
	for(int l=1;l<=t;l++){
		int n,d,p1=1,p2=2;
		cin>>n>>d;
		for(int i=1;i<=n;i++) cin>>a[i];
		while(p2<=n){
			if(a[p2]-a[p1]<=d){ 
				p2++;
				continue;
			}
			
			if(a[p1+1]<=a[p1]+d&&a[p1+2]<=a[p1]+d&&a[p1+1]>=a[p2]-d&&a[p1+2]>=a[p2]-d){
				k++;
			}
			p1++;
			p2++;
		}
	}
	cout<<k-2<<endl<<k-1;
	
	return 0;
}