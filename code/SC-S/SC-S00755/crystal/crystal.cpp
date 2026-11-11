#include<bits/stdc++.h>
using namespace std;
int a[500001],b[500001],c[500001],f[123450],h[100000];
int main(){
	(crystal.in);
	(crystal.out);
	int n,m,x=0;
	cin>>n>>m;
	for(int i=0;i<n;i++){
		cin>>a[i];
	}
	int z;
		sort(a,a+n);
		for(int i=n-1;i>0;i--){
			c[i]=a[i]-a[i-1];
			b[i]=c[i];
		}
		sort(b,b+n);
		
		for(int i=1;i<n;i++){
			int y=1,g=1;
			for(int j=i;;j++){
					f[i]+=y*c[j];
					if(f[i]>m){
				    	h[x]=g;
				    	x++;
				    	break;
					}
				    y++; 
				    g++;
				    
			}
	}
	sort(h,h+n);
	cout<<h[n-2]; 
	return 0;
}