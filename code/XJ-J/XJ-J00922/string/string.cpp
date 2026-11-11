#include<bits/stdc++.h>
using namespace std;
string s,a[100000000000],b[10000000000],c[100000000000];
int n,x,y,e=1,z=0,d=1,f=0;
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>x>>y;
		z=z+x;
		for(int j=e;j<e+x;j++){
			a[i]=y;
			e=j+1;
		}
	}
	for(int i=1;i<=z/2;i++){
		b[i]=a[i];
	}
	for(int i=z;i>z/2;i--){
		c[d]=a[i];
		d++;
	}
	for(int i=1;i<=z/2;i++){
		if(b[i]!=c[i]){
			f=f+1;
		}
	}
	cout<<f;
	return 0;
}