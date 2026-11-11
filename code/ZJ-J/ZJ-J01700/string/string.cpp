#include<bits/stdc++.h>
using namespace std;
int c,n,aa,a[200008],z,y,an;
char l,bb,b[200008];
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>aa>>bb;
		if(bb==l) a[i-1]+=aa;
		else a[i]=aa,b[i]=bb;
	}
	z=1,y=n;
	while(z<y){
		c=min(a[z],a[y]);
		a[z]-=c;
		a[y]-=c;
		if(b[z]!=b[y]){
			an+=c;
		}
		if(a[z]==0) z++;
		if(a[y]==0) y--;
	}
	cout<<an;
	return 0;
} 